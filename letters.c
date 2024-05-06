#include <stdio.h>
#include <ctype.h>
#define false 0
#define true 1

int main()
{
	int ch;
	int flag= -1;
	int flagquote= false;
	
	printf("\n Please insert text \n");
	
	while ((ch=getchar()) != EOF)
	{	
		
		if (ch > '9'|| ch < '0') /* the char is not a digit */
		{
			if (flag < true) /* the char is in the begining of the sentence */
			{
				if(!isspace(ch)) /* the char is not a white char */
					{
						if(ch == '"')
						{
						flagquote= true; /* it means that the next char is in a quote */
						putchar(ch);
						}
						else
						{
						putchar(toupper(ch)); /* the char is the first char of the sentence */
						}
						flag= true; /* the next char will be in the middle of a sentence */
					}
				else
				{
				putchar(ch);
				}
			}

			else
			{
				if(ch == '"')
				{
					if (flagquote== true) /* it means that the char is in the end of a quote */
					{
					flagquote= false;
					putchar(ch);
					}
					else
					{
					putchar(ch);
					flagquote= true;
					}
				}

				else
					{
					if(flagquote== true)
					{
					putchar(toupper(ch)); /* turn all of the chars that are in a quote to capital letters */
					}
					else
					{
					putchar(tolower(ch)); /*  turn all of the chars that are in a sentence to lower letters */
					}
					}
			}
		}
		else
		{
		if (flag < true)
			{
			flag=true;
			}
		}
			
	if (ch== '.' && flagquote== false) /* check if the thar is not in a quote and if the char seymbolize the end of a sentence */
		{
		flag= false; /* the next char will be in the begining of a sentence */
		}
	}
	return 1;
}


