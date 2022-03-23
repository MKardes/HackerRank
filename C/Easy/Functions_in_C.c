#include <stdio.h>

int     max_of_four1(int a, int b, int c, int d) 
//Yavaş çalıştığı için geçemedi. (It didn't be able to pass on the time test.)
{
        if (a < b)
                a = b;
        if (a < c)
                a = c;
        if (a < d)
                a = d;
        return (a);
}

int	max_of_four(int a, int b, int c, int d)
{
	if (a < b)
	{
		if (b < c)
		{
			if (c < d)
				return (d);
			return (c);
		}
		else
		{
			//a < b     c < b   a ! c
			if (b > d)
				return(b);
			return(d);
		}
	}
	else
	{
		//b < a     a > c
		if (a > c)
		{
			if (a > d)
				return(a);
			return (d);
		}
		//b < a     a < c
		else
		{
			if (c > d)
				return (c);
			return(d);
		}
	
	}
}

int	main()
{
	int a, b, c, d;
    	scanf("%d %d %d %d", &a, &b, &c, &d);
    	int ans = max_of_four(a, b, c, d);
    	printf("%d", ans);
    
    	return 0;
}
