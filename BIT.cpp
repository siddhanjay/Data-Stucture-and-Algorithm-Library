//Binary Indexed Tree

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int readSingle(int idx){
int sum = tree[idx]; // sum will be decreased
if (idx > 0){ // special case
    int z = idx - (idx & -idx); // make z first
    idx--; // idx is no important any more, so instead y, you can use idx
    while (idx != z){ // at some iteration idx (y) will become z
        sum -= tree[idx]; 
// substruct tree frequency which is between y and "the same path"
        idx -= (idx & -idx);
    }
}
return sum;
}

void scale(int c){
    for (int i = 1 ; i <= MaxVal ; i++)
        tree[i] = tree[i] / c;
}
// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v)   {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}

