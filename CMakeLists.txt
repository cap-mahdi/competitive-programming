cmake_minimum_required(VERSION 3.24)
project(cp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cp
        CH11InclusionExclusionPrinciple/TotalNumberOfDivisorsProblem.cpp
        CH12PrimeNumbersAndFactorisation/PrimeFactorisation.cpp
        CH12PrimeNumbersAndFactorisation/PrimeQueries.cpp
        CH12PrimeNumbersAndFactorisation/primeSieve.cpp
        CH12PrimeNumbersAndFactorisation/SegmentedSieve.cpp
        CH12PrimeNumbersAndFactorisation/tempCodeRunnerFile.cpp
        CH13ExtendedEuclideanAlgorithm/ExtendedEuclidean.cpp
        CH13ExtendedEuclideanAlgorithm/gcd.cpp
        CH13ExtendedEuclideanAlgorithm/LinearDiophantineEquation.cpp
        CH13ExtendedEuclideanAlgorithm/MultiplicativeModuloInverse.cpp
        CH14NumberTheory/ChineseRemainderTheoreme.cpp
        CH14NumberTheory/EulerTotientFunction.cpp
        CH14NumberTheory/ModuloArithmetic.cpp
        CH14NumberTheory/tempCodeRunnerFile.cpp
        CH15Combinatorics/BinominalCoefficient.cpp
        CH15Combinatorics/birthdayParadox.cpp
        CH15Combinatorics/CatalanNumbers.cpp
        CH16Recursion/CountStrings.cpp
        CH16Recursion/FriendPariringProblem.cpp
        CH16Recursion/RecursionBasics.cpp
        CH16Recursion/tempCodeRunnerFile.cpp
        CH16Recursion/TilingProblem.cpp
        CH16Recursion/TowerOfHanoi.cpp
        CH17BackTracking/8QueenChess-UVA750.cpp
        CH17BackTracking/Brackets.cpp
        CH17BackTracking/NQueenCode.cpp
        CH17BackTracking/permutation.cpp
        CH17BackTracking/subsets.cpp
        CH17BackTracking/SudokuSolver.cpp
        CH17BackTracking/tempCodeRunnerFile.cpp
        CH18BinarySearch/angryBirds.cpp
        CH18BinarySearch/binarySearch.cpp
        CH18BinarySearch/gameOfGreed.cpp
        CH18BinarySearch/occurence.cpp
        CH19DivideAndConquer/inversionCount.cpp
        CH19DivideAndConquer/mergeSort.cpp
        CH19DivideAndConquer/quickSelect.cpp
        CH19DivideAndConquer/quickSort.cpp
        CH19DivideAndConquer/tempCodeRunnerFile.cpp
        CH19DivideAndConquer/ternarySearch.cpp
        CH20GreedyAlgorithms/ActivitySelectionBusyMan.cpp
        CH20GreedyAlgorithms/BiasedStandings.cpp
        CH20GreedyAlgorithms/DEFKIN.cpp
        CH20GreedyAlgorithms/tempCodeRunnerFile.cpp
        CH20GreedyAlgorithms/utiles.cpp
        CH21MeetInTheMiddle/subSums.cpp
        CH22SegmentTrees/segmentTree.cpp
        CH23LazyPropagation/lazyPropagation.cpp
        CH23LazyPropagation/lazyPropagationForMinimum.cpp
        CH23LazyPropagation/tempCodeRunnerFile.cpp
        CH24FenwickTree/dquery-problem.cpp
        CH24FenwickTree/FenwickTree.cpp
        CH24FenwickTree/inversion-count.cpp
        CH25SqrtDecomposition/Mo-algorithm.cpp
        CH25SqrtDecomposition/sqrt-decomposition.cpp
        CH25SqrtDecomposition/tempCodeRunnerFile.cpp
        CH28GraphTraversals/board-game.cpp
        CH28GraphTraversals/Graph.cpp
        CH28GraphTraversals/Graph_cities.cpp
        CH28GraphTraversals/tempCodeRunnerFile.cpp
        CH29GraphsAsTrees/dfs-and-backedges.cpp
        CH29GraphsAsTrees/tree.cpp
        CH30LowestCommonAncestor/LCA-2pointers.cpp
        CH30LowestCommonAncestor/LCA-optimised.cpp
        CH31DirectedGraphs&SCC/Kosaraju-Algorithm.cpp
        CH31DirectedGraphs&SCC/topological-order.cpp
        CH32DisjointSetUnionDataStructure/cycle-detection-using-DSU.cpp
        CH32DisjointSetUnionDataStructure/DSU.cpp
        CH33SpanningTree/KruskalAlgorithm.cpp
        CH33SpanningTree/PrimAlgorithm.cpp
        CH34ShortestPathsAlgorithms/bellman-ford.cpp
        CH34ShortestPathsAlgorithms/djikestra.cpp
        CH34ShortestPathsAlgorithms/floyd-warshall.cpp
        CH34ShortestPathsAlgorithms/tempCodeRunnerFile.cpp
        CH35ClassicalDynamicProgramming/box-stacking.cpp
        CH35ClassicalDynamicProgramming/longest-incerasing-subsequence.cpp
        CH35ClassicalDynamicProgramming/minimum-jumps.cpp
        CH35ClassicalDynamicProgramming/N-K-ladders.cpp
        CH5BitManipulation/allSubSets.cpp
        CH5BitManipulation/tempCodeRunnerFile.cpp
        CH5BitManipulation/TravellingSalesmanProblem.cpp
        CH5BitManipulation/uniqueNumber1.cpp
        CH5BitManipulation/uniqueNumber2.cpp
        CH5BitManipulation/uniqueNumber3.cpp
        CH5BitManipulation/utiles.cpp
        CH7BigIntegers/AddBigIntegers.cpp
        CH7BigIntegers/MultplicationAndFactorial.cpp
        CH7BigIntegers/tempCodeRunnerFile.cpp
        CH8LinearRecurrences&MatrixExponentiation/BinaryExponentiation.cpp
        CH8LinearRecurrences&MatrixExponentiation/BinaryModularExponentiation.cpp
        CH8LinearRecurrences&MatrixExponentiation/FastMultiplication.cpp
        CH8LinearRecurrences&MatrixExponentiation/Fibonacci.cpp
        CH8LinearRecurrences&MatrixExponentiation/SumOfSuiteRecurrent.cpp
        CH9PigeonholePriciple/DIVSUB.cpp
        CH9PigeonholePriciple/GraySimilarCode.cpp
        CH9PigeonholePriciple/HolidayAccomadation.cpp
        CH9PigeonholePriciple/tempCodeRunnerFile.cpp
        File/B.cpp
        Greedy/code.cpp
        Greedy/tempCodeRunnerFile.cpp
        Greedy/template.cpp
        Keyboard/A.cpp
        Keyboard/tempCodeRunnerFile.cpp
        others/LIS/longest-increasing-subsequence.cpp
        others/LIS/problem-spoj.cpp
        "others/Trie Node/maxXORSubarray.cpp"
        "others/Trie Node/trieNode.cpp"
        A.cpp
        A1.cpp
        B-esprit.cpp
        B.cpp
        C.cpp
        code.cpp
        code2.cpp
        code3.cpp
        D.cpp
        dp.cpp
        E.cpp
        G.cpp
        H.cpp
        I.cpp
        L.cpp
        mehdi-khelil.cpp
        seg.cpp
        test.cpp)
