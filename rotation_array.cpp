#include <vector>
#include <iostream>
using namespace std;

bool
isRotation (vector < int >A, vector < int >B)
{

  bool isRotation (false);
 
  if (A.size () != B.size ())
    return isRotation;

  vector < int >::const_iterator iA = A.begin ();

    
  vector < int >::const_iterator iB = B.begin();
  for(; iB != B.end(); iB++) {
      if(*iB == *iA)
        break;
  }

  if (iB == B.end ())
    return isRotation;

  isRotation = true;
  
  iA++; iB++;

  while (iA != A.end () && *iA == *iB)
    {
      
        if (iB == B.end ()) {
	        iB = B.begin ();
	    }

        if (*iA != *iB) {
	        isRotation = false;
	        break;
	    }
	    
	     iA++; iB++;
	     if(iA == A.end()) break;
    }

  return isRotation;
}


int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    vector<int> B = {4, 5, 6, 8, 1, 2, 3};

    bool isRotationArray = isRotation(A, B);
    cout << isRotationArray << endl;
    return 0;
}