# CriticalPathManagement
C++ program to find Critical Path


Sample input with network diagram

	                            17
                         D-------------------->F---->Finish
                         ↑                     ↑
	    0 2 7            7 |                     |
      0 3 7              |    7                |
                         A ------> C           |
      1 4 13                  13               | 26
      4 5 3              B ------> E-----------|
      3 5 17
      5 6 26
     -1 -1 0
