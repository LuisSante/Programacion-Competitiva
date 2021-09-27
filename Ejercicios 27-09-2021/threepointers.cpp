#include <bits/stdc++.h>

using namespace std;

void tree_pointers(int A[], int target, int n){
	int f_pointer = 0;
    int l_pointer = n-1;
	int m_pointer = floor((f_pointer+l_pointer)/2);
	int sum;

	while((sum = A[f_pointer] + A[l_pointer] + A[m_pointer]) != target){
		if(sum < target){
			f_pointer++;
			m_pointer++;
		}

		else if(sum > target){
			l_pointer--;
			m_pointer--;
		}
	}

	cout<<f_pointer<<" "<<m_pointer<<" "<<l_pointer<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int A[] = {1,2,4,5,12};
	int target = 19;
	int n = sizeof(A) / sizeof(A[0]);

	tree_pointers(A,target,n);
    return 0;
}