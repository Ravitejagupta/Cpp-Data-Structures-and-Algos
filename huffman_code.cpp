/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    node* temp = root;
    string r;
    int i = 1;
    while(!s.empty()){        
        if(root->left != nullptr || root->right != nullptr){
            r = s.substr(0,i);
            if (r[i-1] == '1') {root = root->right;}
            else    root = root->left;
            i++;
        }
        else if(root->left == nullptr && root->right == nullptr){
            s = s.substr(i-1);
            cout<<root->data;
            //cout<<s<<endl;
            i=1;
            r = "";
            root = temp;
        }
    }
    
}
