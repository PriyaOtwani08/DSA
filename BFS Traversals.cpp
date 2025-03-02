vector<vector<int>>LevelOrderTraversal(node* root){
    vector<vector<int>>ans; //data structure which is going to store different levels of the tree 
    
    if(root==NULL){ 
        return ans;
    }
    queue<node*>q; //queue of nodes
    q.push(root);
    while(!q.empty()){ //check till queue becomes empty
        int size=q.size();
        vector<int>level;
      for(int i=0;i<size;i++){
        node* node_in_queue=q.front(); 
        q.pop();  
        
        level.push_back(node_in_queue->data); //push data in different levels 
        if(node_in_queue->left!=NULL){  // add left node in queue
            q.push(node_in_queue->left);
        }
        if(node_in_queue->right!=NULL){ //add right node in queue
            q.push(node_in_queue->right);
        }
      }
        ans.push_back(level); //
    }
    
    return ans;
}
