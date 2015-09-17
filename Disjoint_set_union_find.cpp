//Disjoint Set-Union

vector<int> pset(1000); 
void initSet(int _size) { pset.resize(_size); forall (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
int Setcount(int _size)
{
    int a[_size],count=0;
    forall(i,0,_size-1)a[i]=0;
    forall(i,0,_size-1)a[findSet(i)]++;
    forall(i,0,_size-1)if(a[i]!=0)count++;
    return count;
}