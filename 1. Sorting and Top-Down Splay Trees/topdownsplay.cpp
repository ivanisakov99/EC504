#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node Data_Node;
struct Node {
	int code;
	char zip[12];
	char city[150];
	char state[6];
};
struct Tree_node{
    int key;
    Tree_node* lchild;
    Tree_node* rchild;
    Data_Node* data;
};

class SplayTree{
    public:

        SplayTree(){
            }

            // RR(Y rotates to the right
        Tree_node* Right_Rotate(Tree_node* k2){
            // Single rotate the root k2 to the right
            // You have to implement this, return the new root
            Tree_node* k1 = k2->lchild;
            k2->lchild = k1->rchild;
            k1->rchild = k2;
            return k1;

        }
            // LL(Y rotates to the left)
        Tree_node* Left_Rotate(Tree_node* k2){
            // Single rotate the root k2 to the left
            // You have to implement this, return the new root.
            Tree_node* k1 = k2->rchild;
            k2->rchild = k1->lchild;
            k1->lchild = k2;
            return k1;
        }

            // An implementation of top-down splay tree

        Tree_node* Splay(int key, Tree_node* root)
        {//This is one of the things you have to implement

            if (!root)
                return NULL;
            Tree_node Tree;
            /* .......*/
            Tree.lchild = NULL;
            Tree.rchild = NULL;

            Tree_node* LeftTreeMax = &Tree;
            Tree_node* RightTreeMin = &Tree;

            while(1){
                if(key < root->key){
                    if(!root->lchild){
                        break;
                    }

                    if(key < root->lchild->key){
                        root = Right_Rotate(root);
                        if(!root->lchild){
                            break;
                        }
                    }

                    RightTreeMin->lchild = root;
                    RightTreeMin = RightTreeMin->lchild;
                    root = root->lchild;
                    RightTreeMin->lchild = NULL;
                }
                else if(key > root->key){
                    if(!root->rchild){
                        break;
                    }

                    if(key > root->rchild->key){
                        root = Left_Rotate(root);
                        if(!root->rchild){
                            break;
                        }
                    }

                    LeftTreeMax->rchild = root;
                    LeftTreeMax = LeftTreeMax->rchild;
                    root = root->rchild;
                    LeftTreeMax->rchild = NULL;
                }
                else{
                    break;
                }
            }

            LeftTreeMax->rchild = root->lchild;
            RightTreeMin->lchild = root->rchild;
            root->lchild = Tree.rchild;
            root->rchild = Tree.lchild;
            return root;
 
        }

        Tree_node* New_Node(int key) {
            Tree_node*  my_node = new Tree_node;
            if (!my_node){
                fprintf(stderr, "Out of memory!\n");
                exit(1);
            }
            my_node->key = key;
            my_node->lchild = my_node->rchild = NULL;
            return my_node;
        }

        Tree_node* Insert(int key, Tree_node* root){
            Tree_node* my_node = NULL;
            
            my_node = New_Node(key);
            if (!root){
                root = my_node;
                return root;
            }
            root = Splay(key, root);
            if (key < root->key){
                    my_node->lchild = root->lchild;
                    my_node->rchild = root;
                    root->lchild = NULL;
                    root = my_node;
            }
            else if (key > root->key){
                    my_node->rchild = root->rchild;
                    my_node->lchild = root;
                    root->rchild = NULL;
                    root = my_node;
                }
            else { /* it's already in tree, don't add it again*/
                delete my_node;
                return root;
            }
            return root;
        }

        Tree_node* Delete(int key, Tree_node* root){
            Tree_node* temp;
            if (!root)
                return NULL;
            root = Splay(key, root);
            if (key != root->key)
                return root;
            else{
                if (!root->lchild){
                    temp = root;
                    root = root->rchild;
                }
                else {
                    temp = root;
                    root = Splay(key, root->lchild);
                    root->rchild = temp->rchild;
                }
                delete temp;
                return root;
            }

        }

        Tree_node* Search(int key, Tree_node* root){
                return Splay(key, root);
        }

        void InOrder(Tree_node* root){
            if (root){
                InOrder(root->lchild);
                cout<< "key: " <<root->key;
                if(root->lchild)
                    cout<< " | left child: "<< root->lchild->key;
                if(root->rchild)
                    cout << " | right child: " << root->rchild->key;

                cout<< endl;
                InOrder(root->rchild);
            }
        }
};

int main()
    {
        SplayTree st;
        int vector[10] = {9,8,7,6,5,4,3,2,1,0};
        Tree_node *root;
        root = NULL;
        const int length = 10;
        int i;

        for(i = 0; i < length; i++)
            root = st.Insert(vector[i], root);

        cout<<"\nInOrder: \n";

        st.InOrder(root);
        int input;
        input = 6;
        root = st.Search(input, root);
        cout<<"\nAfter Search "<<input<<endl;
        st.InOrder(root);

        input = 3;
        root = st.Search(input, root);
        cout<<"\nAfter Search "<<input<<endl;
        st.InOrder(root);

        input = 8;
        root = st.Delete(input,root);
        cout << "\nAfter Delete "<<input<<endl;
        st.InOrder(root);
        cout<<"\n";
        return 0;
    }
