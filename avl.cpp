#include<iostream>
#include<queue>
using namespace std;



class avl
{   
    public:
    int data;
    avl* left;
    avl* right;
    int height;

    avl(int data): data(data), right(nullptr), left(nullptr){}


    void levelOrderTraversal(avl* root)
    {

        if(root==nullptr)   return;
        queue<avl*>q;
        q.push(root);
        while(!q.empty())
        {
            avl* node=q.front();
            q.pop();

            cout<<node->data<<"  ";

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    void levelOrderUsingVector(avl* root)
    {
        vector<vector<int>> levels;
        if(root==nullptr)   return;
        queue<avl*>q;
        q.push(root);
        q.push(nullptr);    //to mark the end of level

        vector<int> currLevel;

        while(!q.empty())
        {
            avl* node=q.front();
            q.pop();

            if(node==nullptr)//end of level
            {
                levels.push_back(currLevel);
                currLevel.clear();
                if(!q.empty())
                    q.push(nullptr);
            }

            else
            {
                currLevel.push_back(node->data);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

        }

        for(auto level:levels)
        {
            for(int i:level)
                cout<<i<<"  ";
            cout<<endl;
        }
    }

    int heightOfNode(avl* root)
    {
        if(root==nullptr)   return 0;
        return 1+max(heightOfNode(root->left),heightOfNode(root->right));
    }

    int balanceFactor(avl*root)
    {   
        if(root==nullptr)   return 0;
        return heightOfNode(root->left)-heightOfNode(root->right);
    }

    void insert(avl* &root,int d)
    {
        if(root==nullptr)
        {
            avl* node= new avl(d);
            root=node;
            return ;
        }

        if(d>root->data)
        {
            insert(root->right, d);
        }
        else insert(root->left,d);

        root->height=heightOfNode(root);

        int bf=balanceFactor(root);

        if(bf>1 and d<root->left->data)
        {
            root=rightRotation(root);
        }
        else if(bf<-1 and d>root->right->data)
        {
            root=leftRotation(root);
        }
        else if(bf>1 and d>root->left->data)
        {
            root=leftRightRotation(root);
        }
        else if(bf<-1 and d<root->right->data)
        {
            root=rightLeftRotation(root);
        }

    }

    avl* rightRotation(avl* root)
    {
        avl*b=root->left; //55 
        avl*RightSubTreeOfB=b->right; //null
        b->right=root;

        root->left=RightSubTreeOfB; //as right subtree of b is smaller than root, so when root comes down, the right subtree of b will go to left of old root
        root->height=heightOfNode(root);
        b->height=heightOfNode(b);

        return b;
    }
    avl* leftRotation(avl*  root)
    {
        avl*b=root->right;
        avl*LeftSubTreeOfB=b->left;
        b->left=root;

        root->right=LeftSubTreeOfB;
        root->height=heightOfNode(root);
        b->height=heightOfNode(b);

        return b;
    }

//            A     =>  THEN RIGHT ROTATION ON ORIGINAL NODE (ROOT)  
//           /
//          B       =>  FIRST LEFT ROTATION ON B (ROOT->LEFT)
//           \ 
//            C

    avl* leftRightRotation(avl* root)
    {
        root->left=leftRotation(root->left);
        return rightRotation(root);
    }

    avl* rightLeftRotation(avl* root)
    {
        root->right=rightRotation(root->right);
        return leftRotation(root);
    }


};


int main()
{

    avl* r1=new avl(0);
    r1=nullptr;
    
    r1->insert(r1,5);
    r1->insert(r1,6);
    r1->insert(r1,7);
    r1->insert(r1,3);
    r1->insert(r1,4);
    r1->insert(r1,40);
    r1->insert(r1,44);
    r1->insert(r1,30);
    r1->insert(r1,50);

    //r1->levelOrderTraversal(r1);
    cout<<endl;
    r1->levelOrderUsingVector(r1);



    // int arr[]={1,2,3,4,5,6,7,8,9,10};

    // for(int i=0;i<10;i++)
    // {
    //     //unique way to output the array
    //     cout<<*(arr+i)<<"  ";
    // }



    return 0;
}