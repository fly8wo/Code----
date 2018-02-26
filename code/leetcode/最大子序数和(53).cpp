#include <iostream>
using namespace std;
int maxSubArray(vector<int>& nums)
  {
	
	int n = num.size();
	int ans=-2147483648;
	for(int st=0;st<=n;++st)
		for(int ed=st+1;ed<=n;++ed)
		{
			int sum=0;
			for(int i = st;i<ed;i++)
				sum+=nums[i];
					if(sum>ans)
						ans=sum;			
		}
	
	return ans;
	}
}
