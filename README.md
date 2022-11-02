This function can be used when one wants to delete a node in a binary search tree. As it's formal parameters it takes a pointer to root node and the data that needs to be deleted. 

  For the first condition, it checks if root is NULL and returns NULL if the binary search tree is empty.
  
  For the second condition, it checks if the data to be deleted is less than the root data.
    if true it uses recurssion to go to searching on left side of the binary search tree.
    if false it moves to the next condion.
    
  For the third condition, it checks if the data to be deleted is greater than the root data.
    if true it uses recurssion to go to searching on right side of the binary search tree.
    if false it moves to the next condion.
    
  For the fourth condion, we have nested another if...else loop inside it:
    In this condition, we have found the node we are looking for and now want to perform a delete operation on it.
    Before that happens we need to check if it's safe to do so.
    
       The first condition is checking whether the node has children nodes. 
        if it has no children nodes we can safely delete the node and free that space.
        if false we move to the next condition.
        
      The second condition: if the left node is NULL we can safely make the right node take the position of the node we are deleting and then we can safely delete the node and free that space.
      
      The third condition: if the right node is NULL we can safely make the left node take the position of the node we are deleting and then we can safely delete the node and free that space.
      
      The fourth condition: We use a findMin() and pass in the right binary search tree which will return the minimum node in the right side of the binary search tree and therefore we make the node we want to delete have this data. Then finally we call a recurrsive call to the delete() to delete the duplicate. 
 



The whole code would look like this:

     #include<iostream>
    #include<queue>
    using namespace std;

    struct node{
      int data;
      node *left;
      node *right; 
    };

    node* getNewNode(int data){
      node* temp = new node();
      temp->data = data;
      temp->left = NULL;
      temp->right = NULL;

      return temp;
    }
    int findMin(node* rootPtr){

      if(rootPtr == NULL){
        cout<<"Error! Empty tree"<<endl;
        return -1;
      }
      node* temp = rootPtr;

      while(temp->left != NULL){
        temp = temp->left;
      } 

      return temp->data;
    }
    void levelOrder(node* root){
      if(root == NULL){return;}

      queue<node*> Q;
      Q.push(root);

      while(!Q.empty()){
        node* current = Q.front();
        cout<<current->data<<", ";
        if(current->left != NULL){
          Q.push(current->left);
        }
        if(current->right != NULL){
          Q.push(current->right);
        }
        Q.pop();
      }
    }
    node* Delete(node* root, int data){
      if(root == NULL) return root;
      else if(data < root->data) root->left = Delete(root->left, data);
      else if(data > root->data) root->right = Delete(root->right, data);
      else{
        if(root->left == NULL && root->right == NULL){
          delete root;
          root = NULL;
        }else if(root->left == NULL){
          node* temp = root;
          root = root->right;
          delete temp;
        }else if(root->right == NULL){
          node* temp = root;
          root = root->left;
          delete temp;
        }else{
          int temp = findMin(root->right);
          root->data = temp;
          root->right = Delete(root->right, temp);
        }

      }

      return root;
    }
    int main(){
      /*
                7	

            4				9

          1		6

      This is the Binary tree used below.
      */		



      node* root = NULL;

      root = getNewNode(7);
      root->right = getNewNode(9);
      root->left = getNewNode(4);
      root->left->left = getNewNode(1);
      root->left->right = getNewNode(6);

      levelOrder(root);

      int tempDelete;
      cout<<"\nEnter a number to delete from the tree: ";
      cin>>tempDelete;

      Delete(root, tempDelete);

      cout<<endl;
      levelOrder(root);
    }
