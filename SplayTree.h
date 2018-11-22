//
//  SplayTree.h
//  Splay
//
//  Created by Dr. John Charlery on 11/15/16.
//  Copyright (c) 2016 University of the West Indies. All rights reserved.
//

#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayNode
    {
        private:
                int data;            // Node value
    
        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree
    
                //Constructor
                SplayNode( int val ) {data = val; left = right= 0;}
                SplayNode() {left = 0; right= 0;}
    
                //Accessors
                int getData()      const { return data; }
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
    
    
                //Mutators
                void setValue(int val)     { data = val; }
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
    };




class SplayTree
    {
        private:
                SplayNode *root;
    
                    // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(int, SplayNode*);
                SplayNode* InsertHelper(int, SplayNode*);
                string InOrderHelper(SplayNode*);
                string PreOrderHelper(SplayNode*);
                string PostOrderHelper(SplayNode*);
                void insertSplayNodeHelper(SplayNode **, int );
                string displayNodesHelper( SplayNode * ) const;
    
    
            public:
                SplayTree(){ root = 0; };
    
                SplayNode* getRoot(){return root;}
                void Insert(int);
                string InOrder(){ return InOrderHelper(root);}
                string PreOrder(){ return PreOrderHelper(root);}
                string PostOrder(){ return PostOrderHelper(root);}
                void insertSplayNode( int );
                string displayNodes();
    };



//=================================================================================
//          The NEW RightRotate function
//=================================================================================

SplayNode* SplayTree::RightRotate(SplayNode* ptr)
{
    SplayNode* leftchild = ptr->left;
    if (leftchild != NULL)
        {
            ptr->left = leftchild->right;
            leftchild->right = ptr;
        }
    return leftchild;
}



//=================================================================================
//          The NEW LeftRotate function
//=================================================================================

SplayNode* SplayTree::LeftRotate(SplayNode* ptr)
{
    SplayNode* rightchild = ptr->right;
    if (rightchild != NULL)
        {
            ptr->right = rightchild->left;
            rightchild->left = ptr;
        }
    return rightchild;
}





//=================================================================================
//          The NEW Splay function
//=================================================================================

SplayNode* SplayTree::Splay(int key, SplayNode* root)
    {
        if(root == NULL)            // Empty sub-tree; should never be, but...
            return NULL;

        SplayNode *LeftTreeMax, *RightTreeMin;
        SplayNode* header = new SplayNode();

        LeftTreeMax = RightTreeMin = header;

        while(root->left != NULL || root->right != NULL)
            {
                if( key < root->getData() )
                {
                    if( key < root->left->getData() )
                        LeftRotate( root->left );

                    if( root->left == NULL )
                        break;
                    
                    // Link Right
                    RightTreeMin->left = root;
                    RightTreeMin = root;
                    root = root->left;
                }
                else // if( key > root->getData() )
                {
                    if( root->right->getData() < key )
                        RightRotate( root->right );
                    
                    if( root->right == NULL )
                        break;
                    
                    // Link Left
                    LeftTreeMax->right = root;
                    LeftTreeMax = root;
                    root = root->right;
                }

            }
        
        // Assemble Left Tree, Middle Tree and Right tree together
        LeftTreeMax->right = root->left;
        RightTreeMin->left = root->right;
        root->left = header->right;
        root->right = header->left;

        return root;
    }








SplayNode* SplayTree::InsertHelper(int key, SplayNode* root)
    {
        SplayNode* newnode = new SplayNode(key);
    
        if(root == NULL)
            return newnode;
    
        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;
    
        if(key == temp->getData())      // No duplication
            return root;
        
        while(temp != NULL)
            {
                parent_temp = temp;
            
                if(key < temp->getData())
                    temp = temp->left;
                else
                    temp = temp->right;
             }
    
        if(key <= parent_temp->getData())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;
    
        root = Splay(key, root);
        return (root);
    }




void SplayTree::Insert(int key)
{
    root = InsertHelper(key, root);

}



string SplayTree::InOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( InOrderHelper(ptr->left) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
                str.append( InOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PreOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
                str.append( PreOrderHelper(ptr->left) );
                str.append( PreOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PostOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( PostOrderHelper(ptr->left) );
                str.append( PostOrderHelper(ptr->right) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
              }
		return str;
    }



#endif
