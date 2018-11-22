//
//  AVLTree.h
//  AVL
//
//  Created by Dr. John Charlery on 10/6/16.
//  Copyright (c) 2016 University of the West Indies. All rights reserved.
//

#ifndef AVL_AVLTree_H
#define AVL_AVLTree_H




class AVLNode
    {
        private:
            int data;
            int height;
    
        public:
            AVLNode* left;
            AVLNode* right;

            // Constructor functions
            AVLNode()        {right = left = NULL; height = 0;}
            AVLNode(int val) {data = val; height = 0; right = left = NULL;}
    
            // Mutator functions
            void setData(int val)   {data = val;}
            void setHeight(int ht)  {height = ht;}

            // Accessor functions
            int getData()   {return data;}
            int getHeight() { return height;}
     };






class AVL
    {
        private:
            AVLNode* root;
    
            AVLNode* insertHelper(AVLNode*, int);       // Recursive counterpart of insert
            AVLNode* deleteNode(AVLNode*, int);         // Recursive counterpart of delete
            string   preOrderHelper(AVLNode* );         // Recursive counterpart of preorder
            string   postOrderHelper(AVLNode* );        // Recursive counterpart of postorder
            string   inOrderHelper(AVLNode* );          // Recursive counterpart of inorder
            AVLNode* rotateRight(AVLNode* );
            AVLNode* rotateLeft(AVLNode* );
            AVLNode* rotateDoubleRight(AVLNode* );
            AVLNode* rotateDoubleLeft(AVLNode* );
            AVLNode* rotateLeftRight(AVLNode* );
            AVLNode* rotateRightLeft(AVLNode* );
            int      calcHeight(AVLNode* );
            int      calcBalance(AVLNode* );
        
        public:
            AVL() { root = NULL;}
    
            AVLNode* getRoot()       { return root;}
            void     insert(int val) { root = insertHelper(root, val); }
            void     remove(int val) { root = deleteNode(root, val); }
            string   preOrder()      { return preOrderHelper(root); }
            string   postOrder()     { return postOrderHelper(root); }
            string   inOrder()       { return inOrderHelper(root); }
            void     purge()         { root = NULL; }
    };





AVLNode* AVL::insertHelper(AVLNode* ptr, int val)
    {
        if ( ptr == NULL )
            {
                ptr = new AVLNode(val);
            }
        else
            if(val >= ptr->getData())          // insert in right subtree; OP definition
                {
                    ptr->right = insertHelper(ptr->right, val);
                    if(calcBalance(ptr) == -2)          // Too heavy on the right
                        {
                            if(val > ptr->right->getData() )    // Regular right-heavy
                                ptr = rotateDoubleRight(ptr);
                            else                        // It's a special case: ">"
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                if( val < ptr->getData() )
                    {
                        ptr->left = insertHelper(ptr->left, val);
                        if(calcBalance(ptr) == 2)       // Too heavy on the left
                            {
                                if( val < ptr->left->getData() )     // Regular left-heavy
                                    ptr = rotateDoubleLeft(ptr);
                                else                    // It's a special case: "<"
                                    ptr = rotateLeftRight(ptr);
                            }
                    }
    
        ptr->setHeight(calcHeight(ptr));
        return(ptr);
    }





AVLNode*  AVL::deleteNode(AVLNode* ptr, int val)
{
    AVLNode* successor;
    
    if ( ptr == NULL)           // Node location is empty
        {
            return NULL;
        }
    else
        if( val > ptr->getData() )                // Search in Right sub-tree
            {
                ptr->right = deleteNode(ptr->right, val);
                if ( calcBalance(ptr) == 2)
                    {
                        if(calcBalance(ptr->left) >= 0)
                            ptr = rotateDoubleLeft(ptr);
                        else
                            ptr = rotateLeftRight(ptr);
                    }
            }
        else
            if( val < ptr->getData() )          // Search the Left sub-tree
                {
                    ptr->left = deleteNode(ptr->left, val);
                    if( calcBalance(ptr) == -2 )                   //Rebalance during windup
                        {
                            if( calcBalance(ptr->right) <= 0)
                                ptr = rotateDoubleRight(ptr);
                            else
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                {
                    //Node to to be deleted is found
                    if ( ptr->right != NULL)
                        {  //delete its inorder succesor
                            successor = ptr->right;
                            while ( successor->left != NULL)
                                successor = successor->left;
                            
                            ptr->setData( successor->getData() );
                            ptr->right = deleteNode( ptr->right, ptr->getData() );
                            if(calcBalance(ptr) == 2) // Rebalance during windup
                                {
                                    if(calcBalance(ptr->left) >= 0)
                                        ptr = rotateDoubleLeft(ptr);
                                    else
                                        ptr = rotateLeftRight(ptr);
                                }
                    }
                else
                    return(ptr->left);
                
                }
    ptr->setHeight(calcHeight(ptr));
    return(ptr);
}







AVLNode*  AVL::rotateRight(AVLNode* ptr)
    {
        AVLNode* newParent;
    
        newParent = ptr->left;
        ptr->left = newParent->right;
        newParent->right = ptr;
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }





AVLNode*  AVL::rotateLeft(AVLNode* ptr)
    {
        AVLNode* newParent;
    
        newParent = ptr->right;
        ptr->right = newParent->left;
        newParent->left = ptr;
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }





AVLNode*  AVL::rotateDoubleRight(AVLNode* ptr)
    {
        ptr = rotateLeft(ptr);
        return(ptr);
    }





AVLNode*  AVL::rotateDoubleLeft(AVLNode* ptr)
    {
        ptr = rotateRight(ptr);
        return(ptr);
    }





AVLNode*  AVL::rotateLeftRight(AVLNode* ptr)
    {
        ptr->left = rotateLeft(ptr->left);
        ptr = rotateRight(ptr);
        return(ptr);
    }






AVLNode*  AVL::rotateRightLeft(AVLNode* ptr)
    {
        ptr->right = rotateRight(ptr->right);
        ptr = rotateLeft(ptr);
        return(ptr);
    }





int AVL::calcHeight(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
        
        if( ptr == NULL)
            return(0);
        
        if(ptr->left == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->left->getHeight();
        
        if(ptr->right == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->right->getHeight();

    
        if(leftHeight > rightHeight)
            return(leftHeight);
    
        return(rightHeight);
    }





int AVL::calcBalance(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
    
        if(ptr == NULL)
            return (0);
    
        if(ptr->left == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->left->getHeight();
    
        if(ptr->right == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->right->getHeight();
    
        return(leftHeight - rightHeight);
    }






string AVL::inOrderHelper(AVLNode* ptr)
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




string AVL::preOrderHelper(AVLNode* ptr)
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




string AVL::postOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );
                str.append( inOrderHelper(ptr->right) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
             }
		return str;
	}




#endif // defined(AVL_AVLTree_H)
