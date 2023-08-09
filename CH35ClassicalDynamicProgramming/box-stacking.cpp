#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem: Given a set of boxes, where each box has a width, depth and height.
    Find the maximum height of the stack that can be formed by stacking the boxes on top of each other.
    Box A can be place above box B if and only if:
        - A.width < B.width
        - A.depth < B.depth
        - A.height < B.height

    Example:
        boxes = { {2,1,2}, {3,2,3}, {2,2,8}, {2,3,4}, {2,2,1}, {4,4,5} }
        ans = 10
        boxes  = { {2,1,2} , {3,2,3} , {4,4,5} }

    This problem has:
        - optimal substructure: dp[i] = max(dp[i], dp[j] + boxes[i].height) for all j<i and boxes[j] can be placed above boxes[i]
        - overlapping subproblems: dp[i] is calculated multiple times
    ==> Dynamic Programming
        dp[i]: represents the maximum height of the stack that can be formed by stacking the boxes beginning from the ith box


    Approach: sort + dp
        -Sort the boxes based on their height (or width or depth)
        By this sorting we can say that if for every box j that is above box i, then j<i
        That means for every Box i we can only place boxes that are below it in the sorted array and of course they have to satisfy the above condition

        -Intilization: dp[i] = boxes[i].height (because we can only place the ith box)

        - dp[i] = max(dp[i], dp[j] + boxes[i].height) for all j<i and boxes[j] can be placed above boxes[i]

    Complexity:
        O(n^2 + nlogn) = O(n^2)

    Note:
    In the above code,I also printed the boxes that form the maximum height stack
    for that I defined 2 classes
    Box: represents a box
    StackBoxes: represents a stack of boxes and contains hieght of the stack

    so dp[i]: contains the maximum height of the stack that can be formed by stacking the boxes beginning from the ith box and
    also contains the boxes that form the maximum height stack

    For the normal function that answers the function is is called stack_boxes

*/

//my implementation
class Box {
public:
    int h, w, d;
    Box(int w, int d, int h) {
        this->h = h;
        this->w = w;
        this->d = d;
    }
    bool operator<(Box other) {
        return other.h > h && other.w > w && other.d > d;
    }
    void print() {
        cout << "[" << w << "," << d << "," << h << "]" << "\n";
    }
};
class StackBoxes {
public:
    stack<Box> s;
    int height = 0;
    StackBoxes(Box b) {
        height = b.h;
        s.push(b);
    }
    StackBoxes() {
    }
    void addStack(StackBoxes b) {
        height += b.height;
        stack<Box> temp;
        while (b.s.empty() == false) {
            Box box = b.s.top();
            b.s.pop();
            temp.push(box);
        }
        while (temp.empty() == false) {
            Box box = temp.top();
            temp.pop();
            s.push(box);
        }
    }

};

bool compare(Box a, Box b) {
    return a.h < b.h;
}


int bottom_up(vector<Box> boxes) {
    int n = boxes.size();
    vector<StackBoxes> dp(n);

    sort(boxes.begin(), boxes.end(), compare);

    for (int i = 0;i < n;i++) {
        dp[i] = Box(boxes[i]);
    }

    for (int i = 1;i < n;i++) {
        int m = boxes[i].h;
        int maxForThisBox = m;
        StackBoxes stackToBeAdded;
        for (int j = 0;j < i;j++) {
            if (boxes[j] < boxes[i]) {

                if (maxForThisBox < m + dp[j].height) {
                    stackToBeAdded = dp[j];
                    maxForThisBox = m + dp[j].height;
                }
            }
        }

        dp[i].addStack(stackToBeAdded);
    }
    StackBoxes ans = dp[0];
    for (int i = 1;i < n;i++) {
        if (ans.height < dp[i].height) {
            ans = dp[i];
        }
    }
    stack <Box> temp(ans.s);
    while (temp.empty() == false) {
        Box box = temp.top();
        temp.pop();
        box.print();
    }
    return ans.height;
}

//normal function that answers the question
bool compareBoxes(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
bool canPlace(vector<int> a, vector<int> b) {
    return a[0] < b[0] && a[1] < b[1] && a[2] < b[2];
}

int stack_boxes(vector < vector<int>> boxes) {
    int n = boxes.size();
    vector<int> dp(n);
    sort(boxes.begin(), boxes.end(), compareBoxes);
    for (int i = 0;i < n;i++) {
        dp[i] = boxes[i][2];
    }
    for (int i = 1;i < n;i++) {
        int m = boxes[i][2];
        for (int j = 0;j < i;j++) {
            if (canPlace(boxes[j], boxes[i])) {
                dp[i] = max(dp[i], dp[j] + m);
            }
        }
    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solve() {
    vector<Box> boxes = {
        Box(2,1,2),
        Box(3,2,3),
        Box(2,2,8),
        Box(2,3,4),
        Box(2,2,1),
        Box(4,4,5)
    };
    cout << bottom_up(boxes) << endl;

    //same example  for the normal function
    vector<vector<int>> boxes2 = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };
    cout << stack_boxes(boxes2) << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}