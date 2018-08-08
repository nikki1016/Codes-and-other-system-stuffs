int s[400005];		// Segment Tree
int lazy[400005];	// Lazy Array

void update(int idx, int l, int r, int x, int y, int v) {
    if(lazy[idx]) { // If there was a pending update, perform the update on the node and mark the children (if any) with pending updates (lazy)
		if(l!=r) {
			lazy[2*idx+1] += lazy[idx];
			lazy[2*idx+2] += lazy[idx];
		}
		s[idx] += (r-l+1)*lazy[idx];
		lazy[idx] = 0;
    }
    if(r<x || l>y || l>r) return; 	// Out of range
    if(l>=x && r<=y) { 				// Segment lying entirely inside
		s[idx] += (r-l+1)*v; 	// Update current node
		if(l!=r) { 					// Mark the children (if any) with pending updates (lazy)
			lazy[2*idx+1] += v;
			lazy[2*idx+2] += v;
		}
		return;
    }
    int mid = (l+r)/2;
    update(2*idx+1,l,mid,x,y,v);
    update(2*idx+2,mid+1,r,x,y,v);
    s[idx] = s[2*idx+1] + s[2*idx+2]; // Update the node.
}

int query(int idx, int l, int r, int x, int y) {
    if(lazy[idx]) { // If there was a pending update, perform the update on the node and mark the children (if any) with pending updates (lazy)
		if(l!=r) {
			lazy[2*idx+1] += lazy[idx];
			lazy[2*idx+2] += lazy[idx];
		}
		s[idx] += (r-l+1)*lazy[idx];
		lazy[idx] = 0;
    }
    if(r<x || l>y || l>r) return 0; 	// Out of range
    if(l>=x && r<=y) { 					// Segment lying entirely inside
		return s[idx];
    }
    int mid = (l+r)/2;
    return query(2*idx+1,l,mid,x,y) + query(2*idx+2,mid+1,r,x,y);
}
