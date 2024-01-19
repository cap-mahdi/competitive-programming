Un module GPS envoie beaucoup type de trames,on va s'intéresser à 2 types de trames:
- GGA: Global Positioning System Fix Data
- RMC: Recommended Minimum Specific GNSS Data
ces 2 trames en ensemble nous donne les informations necessaires pour le projet.


Trame GGA: de la forme : $GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
exemple (celui qu'on va envoyé): $GPGGA,180105.00,4318.85531,N,00021.88413,W,1,05,5.24,203.2,M,49.1,M,,*48
Analyse de la trame:
- hhmmss.ss : heure, minute, seconde et millisecondes (UTC) => dans notre exemple: 18h01m05s
- llll.ll : latitude (degrés décimaux) => dans notre exemple: 43°18.85531'N
- a : latitude (N ou S) => dans notre exemple: N pour Nord
- yyyyy.yy : longitude (degrés décimaux) => dans notre exemple: 000°21.88413'W
- a : longitude (E ou W) => dans notre exemple: W pour West
- x : qualité du fix GPS (0 = fix non disponible, 1 = GPS fix, 2 = Differential GPS fix) => dans notre exemple: 1
- xx : nombre de satellites utilisés => dans notre exemple: 05
- x.x : précision horizontale (mètres) : A ne pas extraire
- x.x : altitude (mètres) => dans notre exemple: 203.2
- M : unité d'altitude (M = mètres) => dans notre exemple: M pour mètres
- les autres champs ne nous intéressent pas

Trame RMC: de la forme : $GPRMC,hhmmss.ss,a,llll.ll,a,yyyyy.yy,a,x.x,x.x,ddmmyy,,,a*hh
exemple (celui qu'on va envoyé): $GPRMC,180115,A,4807.038,N,01131.000,E,022.4,084.4,231223,003.1,W*6A
Analyse de la trame:
- hhmmss.ss : heure, minute, seconde (UTC) => dans notre exemple: 18h01m15s
- a : status (A = data valid, V = data not valid) => dans notre exemple: A
- llll.ll : latitude (degrés décimaux) => dans notre exemple: 48°07.038'N
- a : latitude (N ou S) => dans notre exemple: N pour Nord
- yyyyy.yy : longitude (degrés décimaux) => dans notre exemple: 011°31.000'E
- a : longitude (E ou W) => dans notre exemple: E pour East
- x.x : vitesse au sol (nœuds) => dans notre exemple: 022.4
- x.x : cap au sol => dans notre exemple: 084.4
- ddmmyy : date (jour, mois, année) => dans notre exemple: 23/12/2023
- les autres champs ne nous intéressent pas



voici mais handlers :
void SysTick_Handler(void)
{
    static int count = 0;
    count++;

    if (count == PERIOD_BETWEEN_ACCEPTING_DATA_IN_SECONDS * 10)
    {
        // IF 60 seconds have passed, then we can accept data again
        DMA_Cmd(DMA1_Channel5, ENABLE);
        count = 0;
    }
}

void DMA1_Channel5_IRQHandler(void)
{
    if (DMA_GetITStatus(DMA1_IT_TC5))
    {
        // IF DMA transfer is complete on channel 5, then we can process the data
        extractData(Receive_Buffer, &gpsData);

        // Disable DMA channel to avoid interference while configuring
        DMA_ClearITPendingBit(DMA1_IT_TC5);
        DMA_Cmd(DMA1_Channel5, DISABLE);
        DMA_SetCurrDataCounter(DMA1_Channel5, MAX_TRAME_LENGTH);
    }
}

void DMA1_Channel7_IRQHandler(void)
{
    if (DMA_GetITStatus(DMA1_IT_TC7))
    {
        // IF DMA transfer is complete on channel 7, then we can disable the channel
        DMA_Cmd(DMA1_Channel7, DISABLE);
        DMA_ClearITPendingBit(DMA1_IT_TC7);
    }
}

void EXTI15_10_IRQHandler(void)
{
    uint32_t Transmit_Buffer_Size;
    if (EXTI_GetITStatus(EXTI_Line13) != RESET)
    {

        // Call the function to process and format data
        Transmit_Buffer_Size = processAndFormatData(gpsData, Transmit_Buffer);

        // Set the data counter for DMA
        DMA_SetCurrDataCounter(DMA1_Channel7, Transmit_Buffer_Size);

        // Enable DMA channel to start transmission
        DMA_Cmd(DMA1_Channel7, ENABLE);

        // Clear EXTI Line 13 pending bit
        EXTI_ClearITPendingBit(EXTI_Line13);
    }
}


alors comme on peut voir on a utilise 4 interruptions:

-DMA1_Channel5_IRQn : pour la reception des données du GPS du port USART1
-DMA1_Channel7_IRQn : pour l'envoie des données vers le port USART2


on ne sait pas la taille,ca depend du taille qu’on va transmettre,donc on va utiliser la fonction         DMA_SetCurrDataCounter(DMA1_Channel7, Transmit_Buffer_Size);



const int MAX_TRAME_LENGTH = 100; => La taille varie donc on va prendre une taille assez grande pour ne pas avoir des problemes

char Receive_Buffer[MAX_TRAME_LENGTH]; => Buffer pour recevoir les données du GPS

char Transmit_Buffer[300]; => Buffer pour envoyer les données vers le port USART2

const int PERIOD_BETWEEN_ACCEPTING_DATA_IN_SECONDS = 60; => On va accepter les données du GPS (DMA_Cmd(DMA1_Channel5, ENABLE);) chaque 60 secondes

GPS_Structure gpsData; // Inclue au code avec une implementation pour editer les trames reçcus et les sauvegarder au niveau des instances de cette structure là.


Il y rien dans la boucle while du main, car tout est géré par les interruptions et leurs handlers.


comment le projet fonctionne?
comme on a dit le module GPS va envoyer 2 types de trames soit GPS soit RMC, le probleme c'est que meme pour le meme type de trame, la taille peut varier.
C'est pour cela on a declaré une constante nomme MAX_TRAME_LENGTH (=100) pour la taille maximale d'une trame.

Alors au debut, le transfert sur le canal 5 du DMA1 est activé pour recevoir les données du GPS, Le GPS va envoyé d'une façon continue les données, d'une maniere tres rapide, alors le Transfer Complete Interrupt (TC) va etre declenché tres rapidement. Apres le TC,on va desactiver le transfert sur le canal 5 du DMA1 pour eviter des problemes, et on va activer le SysTick Timer pour compter 60 secondes, apres 60 secondes, on va activer le transfert sur le canal 5 du DMA1 pour recevoir les données du GPS, et ainsi de suite.

Avec notre approche, on peut traiter n'importe quelle taille de trame, mais dans Receiver_Buffer on va avoir une trame complete et une autre trame incomplete, on va bien sur traiter la trame complete et on va ignorer la trame incomplete.

Des que le transfert sur le canal 5 du DMA1 est fini,on va appeler des fonctions utiles pour nous aider à extracter et formatter les données du GPS, et on va sauvegarder les données dans une instance de la structure GPS_Structure et dans un buffer nomme Transmit_Buffer.

Si on appuie sur le bouton bleu, on va activer le transfert sur le canal 7 du DMA1 pour envoyer les données du GPS vers le port USART2, et on va desactiver le transfert sur le canal 7 du DMA1 apres le transfert des données.


Comme on a dit, le trame de GGA1() a ete bien recu et traite (1ere trame recu) et le 2eme trame a ete ignoree ,c’est just pour resoudre le probleme de taille  <= corrige et ajouter des accents

Comme on a dit,le trame de GGA1() a été bien reçu et traité (1ere trame reçu) et le 2eme trame a été ignorée ,c’est just pour résoudre le problème de taille
la Date reste : _ _ / _ _ / _ _ _ _  car la date est une information dans RMC1() et on a pas traite jusqu’à maintenant une trame de type RMC


une minute 


Une chose à noter est qu’au premier transfert , le ‘$’ va etre dans la 1ere position (0) du receive_buffer mais dans les autres transferts , le ‘$’ va etre dans le 2eme position (1) car il y a un charactere non envoye qui reste toujours et qui va etre 

Une chose à noter est qu'au premier transfert, le '$' va etre dans la 1ere position (0) du receive_buffer mais dans les autres transferts, le '$' va etre dans la 2eme position (1) car il y a un charactére non envoyé qui reste toujours et qui va etre envoyé dans le prochain transfert, donc il va occuper la premiere position (0) du receive_buffer.(on peut eliminer ce probleme en utilisant USART1_IRQHandler mais c'est pas necessaire, pour faire une interruption pour ce raison)