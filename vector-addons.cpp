template <typename T>
void pvec(const vector<T>& arr) 
{
    for (auto elem:arr) 
    {
        cout << elem << " ";
    }
    cout << "\n";
}

template <typename T>
bool checkCommon(const vector <T>& v1, const vector <T>& v2) 
{
    typename vector <T>::iterator it1 = v1.begin();
    typename vector <T>::iterator it2 = v2.begin();
    while(it1 != v1.end() && it2 != v2.end()) 
    {
        if (*it1 == *it2) 
        {
            return true;
        }
        if (*it1 < *it2) 
        {
            it1 = lower_bound(it1, v1.end(), *it2);
        }
        else if (*it2 < *it1) 
        {
            it2 = lower_bound(it2, v2.end(), *it1);
        }
    }
    return false;
}