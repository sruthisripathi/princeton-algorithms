class Node {
    public:
        int val;
        Node *next;
        Node *prev;

        Node(int v)
            : val(v),
              next(nullptr),
              prev(nullptr) {}
};
