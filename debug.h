template<class T>void print(T x)
{
  cerr << x << " ";
}
template<class T, class V> void print(pair<T , V> x)
{
  print(x.first);
  cerr << ':';
  print(x.second);
  cerr<<"\n";
}
template<class T>void print(vector<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template<class T>void print(set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template<class T>void print(set<T,greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template<class T>void print(multiset<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template<class T>void print(multiset<T,greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template<class T>void print(unordered_set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template<class T, class V>void print(vector<pair<T, V>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x.first);
    cerr << ":";
    print(x.second);
    cerr << ' ';
  }
  cerr << ']';
  cerr<<"\n";

}
template <class T, class V>void print(map <T, V> &a)
{
  cerr << "[ ";
  for (auto i : a)
  {
    print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr<<"\n";

}
template <class T, class V>void print(unordered_map <T, V> &a)
{
  cerr << "[ ";
  for (auto i : a)
  {
    print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr<<"\n";

}
template <class T>void print(vector<vector<T>> &a)
{
  cerr << "[\n ";
  for (auto i : a)
  {
    print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr<<"\n";

}
 