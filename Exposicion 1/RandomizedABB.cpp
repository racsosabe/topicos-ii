#include<bits/stdc++.h>
using namespace::std;

// Expected height: O(logn)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

struct node{
	int val;
	node* left;
	node* right;
	node(int val) : val(val) {
		left = NULL;
		right = NULL;
	}
};

node* root = NULL;

void DFS(node* u){
	if(u == NULL) return;
	DFS(u -> left);
	cout << u -> val << endl;
	DFS(u -> right);
}

void insert(node* &u, int X){
	if(u == NULL){
		u = new node(X);
		return;
	}
	if(u -> val < X){
		if(u -> right == NULL){
			u -> right = new node(X);
		}
		else{
			insert(u -> right, X);
		}
	}
	else{
		if(u -> left == NULL){
			u -> left = new node(X);
		}
		else{
			insert(u -> left, X);
		}
	}
}

bool search(node* u, int X){
	if(u == NULL) return false;
	if(u -> val == X) return true;
	if(u -> val < X) return u -> right ? search(u -> right, X) : false;
	return u -> left ? search(u -> left, X) : false;
}

void randomize(vector<int> &v){
	int n = v.size();
	for(int i = 1; i < n; i++){
		int p = random(0, i);
		swap(v[i], v[p]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> values;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		values.emplace_back(x);
	}
	randomize(values);
	for(auto x : values){
		insert(root, x);
	}
	int m;
	scanf("%d", &m);
	while(m--){
		int x;
		scanf("%d", &x);
		printf("%d%s en el arbol\n", x, (search(root, x) ? " esta" : " no esta"));
	}
	return 0;
}
