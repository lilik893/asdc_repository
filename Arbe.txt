using namespace std;

class Arbore{


    struct Node{
        Node(Processor x) : data(x){}
        Processor data;
        struct Node* left;
        struct Node* right;

    };
    Node* root;
    Node* makeEmpty(Node* t){
        if(t == NULL)
            return NULL;{
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    Node* insert(Processor x, Node*& t){
        if(t == NULL){
            t = new struct Node(x);
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x.id < t->data.id)
            t->left = insert(x, t->left);
        else if(x.id > t->data.id)
            t->right = insert(x, t->right);
        return t;
    }
     Node* find(Node* t, int x){
         int nr=0;
        while(t!=NULL){
            if( t->data.id == x){
                cout<<"Lungimea teoretica de cautare este: " << (log(nr)/log(2) + 2)<<endl;
                cout<<"Sau efectuat "<<nr<<" iteratii in arbori binari de cautare"<<endl;
                t->data.afisare();
                return t;}

            else if(x < t->data.id)
                t=t->left;
            else if(x > t->data.id)
                t=t->right;
            nr++;}
        cout<<"Data Not Found"<<endl;
        t->data.id=-1;
        return t;
    }
    public:
        Arbore(){
            root = NULL;
        }

        ~Arbore(){
            root = makeEmpty(root);
        }

        void insert(Processor x){
            root = insert(x, root);
        }
        void search(int x){
            root = find(root, x);
        }
};