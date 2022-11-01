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
			node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	
	}
	
	return root;
}
