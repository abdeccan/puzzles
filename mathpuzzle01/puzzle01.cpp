#include <iostream>
using namespace std;

/*
	 a      d      g
	---  + --- +  ---  =  1
	b c    e f    h i 
*/


int main()
{
	//double fraction1 = 1.0 / 3;
	//double fraction2 = 2.0 / 3;
	//double sum = fraction1 + fraction2;
	//cout << "Sum is " << sum << endl;

	//for (int a = 1; a < 10; a++)
	//{
	//	for (int b = 1; b < 10 && a != b; b++)
	//	{
	//		for (int c = 1; c < 10 && c != a && c != b; c++)
	//		{
	//			for (int d = 1; d < 10 && d != a && d !=b && d != c; d++)
	//			{
	//				for (int e = 1; e < 10 && e != a && e != b && e != c && e != d; e++)
	//				{
	//					for (int f = 1; f < 10 && f != a && f != b && f != c && f != d && f != e; f++)
	//					{
	//						for (int g = 1; g < 10 && g != a && g != b && g != c && g != d && g != e && g != f; g++)
	//						{
	//							for (int h = 1; h < 10 && h != a && h !=b && h != c && h != d && h != e && h != f && h != g; h++)
	//							{
	//								for (int i = 1; i < 10 && i != a && i !=b && i != c && i != d && i != e && i != f && i != g && i != h; i++)
	//								{
	//									if ((a * 1.0) / (10 * b + c) + (d * 1.0) / (10 * e + f) + (g * 1.0) / (10 * h + i) == 1)
	//									{
	//										printf("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d, g=%d, h=%d, i=%d\n", a, b, c, d, e, f, g, h, i);
	//									}
	//								}
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
		{
			if (a == b) continue;
			for (int c = 1; c < 10; c++)
			{
				if (a == c || b == c) continue;
				for (int d = 1; d < 10; d++)
				{
					if (a == d || b == d || c == d) continue;
					for (int e = 1; e < 10; e++)
					{
						if (a == e || b == e || c == e || d == e) continue;
						for (int f = 1; f < 10; f++)
						{
							if (a == f || b == f || c == f || d == f || e == f) continue;
							for (int g = 1; g < 10; g++)
							{
								if (a == g || b == g || c == g || d == g || e == g || f == g) continue;
								for (int h = 1; h < 10; h++)
								{
									if (a == h || b == h || c == h || d == h || e == h || f == h || g == h) continue;
									for (int i = 1; i < 10; i++)
									{
										if (a == i || b == i || c == i || d == i || e == i || f == i || g == i || h == i) continue;
										if ((a * 1.0) / (10 * b + c) + (d * 1.0) / (10 * e + f) + (g * 1.0) / (10 * h + i) == 1)
										{
											printf("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d, g=%d, h=%d, i=%d\n", a, b, c, d, e, f, g, h, i);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}