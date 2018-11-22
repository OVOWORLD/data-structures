//
//  BSTree.h
//  BST
//
//  Created by Dr. John Charlery on 6/8/15.
//  Copyright (c) 2015 University of the West Indies. All rights reserved.
//

#ifndef BST_BSTree_h
#define BST_BSTree_h


class BSTNode
    {
        private:
            int data;
    
        public:
            BSTNode* left;
            BSTNode* right;

            // Constructor functions
            BSTNode(){right = left = NULL;}
            BSTNode(int val){data = val; right = left = NULL;}
    
            // Mutator functions
            void setData(int val){data = val;}

            // Accessor functions
            int getData(){return data;}
     };







class BST
    {
        private:
            BSTNode* root;
    
            // Recursive counterpart for inserting a node
            BSTNode* insertHelper(BSTNode*, int);
    
            // Recursive counterpart for deleting a node
            BSTNode* deleteNode(BSTNode*, int);
    
            // Recursive counterpart of preorder traversal
            string preOrderHelper(BSTNode* );
    
            // Recursive counterpart of postorder traversal
            string postOrderHelper(BSTNode* );

            // Recursive counterpart of inorder traversal
            string inOrderHelper(BSTNode* );
    
        public:
            //  Constructor function
            BST() { root = NULL;}
    
            // Mutator functions
            void purge() { root = NULL;}
            void insert(int val) { root = insertHelper(root, val); }
            void remove(int val) { root = deleteNode(root, val); }
   
            // Accessor functions
            BSTNode* getRoot() { return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }
    
            string showLevels();        //Display nodes by level
    };





BSTNode* BST::insertHelper(BSTNode* ptr, int val)
    {
        if ( ptr == NULL )         // The tree is empty - new first node!
            {
                ptr = new BSTNode(val);
            }
        else                       // choose which sub-tree to follow
            {
                if (val >= ptr->getData())  // insert in right subtree - Operational defn.
                    ptr->right = insertHelper(ptr->right, val);
                else
                    ptr->left = insertHelper(ptr->left, val);
            }
        return ptr;
    }





BSTNode*  BST::deleteNode(BSTNode* ptr, int val)
    {
        BSTNode* successor;
        
        if ( ptr == NULL)           // Node not found!
            {
                return NULL;
            }
        else
            if ( val > ptr->getData() )                // Search in Right subtree
                    ptr->right = deleteNode(ptr->right, val);
            else if( val < ptr->getData() )           // Search in Left subtree
                        ptr->left = deleteNode(ptr->left, val);
        
                 else   //Node to to be deleted is found
                     {
                        if ( ptr->right != NULL )
                            {  // delete its inorder succesor
                                successor = ptr->right;                 // Go right...
                                while ( successor->left != NULL )       // ...then go deep left
                                    successor = successor->left;
                                
                                // Transfer data from successor to ptr
                                ptr->setData( successor->getData() );
                                
                                // Now reset ptr's right child
                                ptr->right = deleteNode( ptr->right, ptr->getData() );
                            }
                        else
                            return (ptr->left);
                    }
        return (ptr);
    }







string BST::inOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
                str.append( inOrderHelper(ptr->right) );
              }
		return str;
	}




string BST::preOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
                str.append( preOrderHelper(ptr->left) );
                str.append( preOrderHelper(ptr->right) );
              }
		return str;
	}




string BST::postOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( postOrderHelper(ptr->left) );
                str.append( postOrderHelper(ptr->right) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
             }
		return str;
	}





string BST::showLevels()
    {
        vector <BSTNode*> listA;
        vector <BSTNode*> listB;
    
        string str = "";
        
        listA.resize(0);
        listB.resize(0);
        
        if (root == NULL)
            {
                str.append("Tree is Empty...\n");
                return str;
            }
        else
            listA.push_back(root);

    
        while (!listA.empty())
            {
                //Display the contents of listA
                for (int x = 0; x < listA.size(); x++)
                    {
                        str.append(to_string(listA[x]->getData()));
                        str.append("\t");
                    }
                str.append("\n");
            
                //Transfer contents of listA to listB
                listB = listA;
            
                // Now purge listA and copy listB's children into listA
                listA.resize(0);

                for (int x = 0; x < listB.size(); x++)
                    {
                        if (listB[x]->left != NULL)
                            listA.push_back(listB[x]->left);
                        if (listB[x]->right != NULL)
                            listA.push_back(listB[x]->right);
                    }
            }
        return str;
    }




#endif
