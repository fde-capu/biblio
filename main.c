/* ******************************************* */
/*                                             */
/*                     :|||::|||:||||:::|||||| */
/* main.c              :|::||::|::|:||::::||:| */
/*                     |:|:|:::|::::::|:|:|||: */
/*     ::|||| <::||||>                         */
/*                                             */
/* C20191213095912 ::||||                      */
/* U20191215165255 :||:||                      */
/*                                             */
/* ******************************************* */

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# define NL printf("\n");
# define J(x) if (*j == x[0])
# define JJ(x) if ((*j == x[0]) && (*(j + 1) == x[1]))
# define JJJ(x) if ((*j == x[0]) && (*(j + 1) == x[1]) && (*(j + 2) == x[2]))
# define N j = next_line(j);
# define NC N continue;

typedef struct	book
{
	char	*a;
	char	*t;
	char	*r;
	char	*e;
	char	*p;
	char	*y;
	char	*o;
	char	*l;
	char	*i;
	char	*n;
	struct book	*pv;
	struct book	*nx;
}	book;

book	*init_book(book *n)
{
	book	*b;
	b = malloc(sizeof(book));
	b->a = 0;
	b->t = 0;
	b->r = 0;
	b->e = 0;
	b->p = 0;
	b->y = 0;
	b->o = 0;
	b->l = 0;
	b->i = 0;
	b->n = 0;
	b->nx = n;
	b->pv = 0;
	if (n) n->pv = b;
	return (b);
}

char	*until_line(char *f)
{
	char	*o;
	char	*p;
	char	*w;
	int		len;

	p = f;
	len = 0;
	while (*p != '\n')
		len++;
	o = malloc(len);
	w = o;
	p = f;
	while (--len)
	{
		*w = *p;
		w++;
		p++;
	}
	*w = 0;
	return (o);
}

char	*file_content(char *fn)
{
	char	*buffer;
	long	length;
	FILE	*f;
	char	*out;

	buffer = 0;
	f = fopen (fn, "r");
	if (f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc (length + 1);
		out = buffer;
		if (buffer)
		{
			fread(buffer, 1, length, f);
		}
		fclose(f);
	}
	buffer[length] = 0;
	return (out);
}

char	*next_line(char *j)
{
	while ((*j) && (*j != '\n'))
		j++;
	j++;
	return (j);
}

char	*get_line(char *j)
{
	int		len;
	char	*line;
	char	*l;

	len = 0;
	while ((*++j) && (*j != '\n'))
		len++;
	line = malloc(len + 1);
	l = line;
	*(l + len) = 0;
	while (--len > 0)
	{
		//printf("len %d, j %c ", len, j[0]);
		//fflush(stdout);
		*(l + len) = *--j;
	}
	return (l + 1);
}

int		length(char *c)
{
	int	z;

	if (!c) return (0);
	z = 0;
	while (*c)
	{
		c++;
		z++;
	}
	return (z);
}

char	*put_str(char *in, char *m)
{
	if (!in) return (m);
	while (*in)
	{
		*m = *in;
		in++;
		m++;
	}
	return (m);
}

char	*achar(char *u)
{
	char	*r;
	char	*p;
	char	*d;

	if (*u != '\\')
	{
		r = malloc(2);
		r[0] = *u;
		r[1] = 0;
	}
	else
	{
		u++;
		if (*u == '<') d = "&lt;\0";
		if (*u == '>') d = "&gt;\0";
		r = malloc(length(d));
		p = r;
		while (*d)
		{
			*p = *d;
			p++;
			d++;
		}
	}
	return (r);
}

char	u_case(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	return (c);
}

char	*format_a(char *i)
{
	char	*o;
	char	*p;
	int		n;
	char	*w;
	char	*et;
	char	etal[] = "; et al";
	char	upper[] = "<span style='text-transform:uppercase'>";
	char	normal[] = "</span>";
	char	*u;
	char	*l;
	int		c;

	c = 0;
	u = &upper[0];
	l = &normal[0];
	et = etal;
	o = malloc(length(i) * 2);
	w = o;
	p = i;
	n = 1;
	while (*p)
	{
		if (*p == ';')
			n++;
		p++;
	}
	p = i;
	w = put_str(u, w);
		while (*p)
		{
			if (*p == ',')
			{
				w = put_str(l, w);
			}
			if (*p == ';')
			{
				w = put_str(l, w);
				w = put_str(u, w);
				c++;
			}
			*w = *p;
			if ((n >= 4) && (c == 2))
			{
				w = put_str(l, w);
				w = put_str(et, w);	
			}
			w++;
			p++;
		}
	w = put_str(l, w);
	*w = 0;
	return (o);
}

char	*print_book(book *b, char *t)
{
	char	*u;
	char	*a;
	char	*p;
	book	*c;
	int		len;
	char	*myc;

	len = 0;
	c = b;
	while (c)
	{
		len+=10;
		len += length(t);
		len += length(c->a);
		len += length(c->t);
		len += length(c->r);
		len += length(c->e);
		len += length(c->p);
		len += length(c->y);
		len += length(c->o);
		len += length(c->l);
		len += length(c->i);
		len += length(c->n);
		c = c->nx;
	}
	a = malloc(len);
	p = a;
	while (b)
	{
		u = t;
		if (b->a)
		{
			while (*u)
			{
				if (*u == '$')
				{
					u++;
					if (*u == 'A') 
					{
						p = put_str(format_a(b->a), p);
					}
					if (*u == 'T') 
					{
						p = put_str(b->t, p);
						if ((*(p - 1) == '!')
						|| (*(p - 1) == '?'))
						{
							u += 1;
						}
					}
					if (*u == 'R') 
					{
						if (b->r)
						{
							p = put_str(b->r, p);
						}
						else
						{
							p -= 3;
							u += 6;
						}
					}
					if (*u == 'E') 
					{
						if (b->e)
						{
							p = put_str(b->e, p);
						}
						else
						{
							u += 2;
						}
					}
					if (*u == 'P') 
					{
						if (b->p)
						{
							p = put_str(b->p, p);
						}
						else
						{
							u += 2;
						}
					}
					if (*u == 'Y') 
					{
						p = put_str(b->y, p);
					}
					if (*u == 'O') 
					{
						if (b->o)
						{
							p = put_str("Online", p);
						}
						else
						{
							u += 2;
						}
					}
					if (*u == 'L') 
					{
						p = put_str(b->l, p);
					}
					if (*u == 'I') 
					{
						p = put_str(b->i, p);
					}
					if (*u == 'N') 
					{
						if (b->n)
						{
							p = put_str(b->n, p);
						}
						else
						{
							u += 2;
						}
					}
				}
				else
				{
					myc = achar(u);
					p = put_str(myc, p);
					if ((*myc == '&') && (*(myc + (length(myc) - 1)) == ';'))
					{
						u++;
					}
				}
				u++;
			}
		}
		p = put_str("\n\n", p);
		b = b->nx;
	}
	p = put_str("\0", p);
	//printf("%s", a);
	return (a);
}

void	save_book(char *bib)
{
	FILE	*f;

	f = fopen ("bibli.htm", "w");
	fprintf(f, "%s", bib);
	fclose (f);
	return ;

}

void	open_browser(char *f)
{
	// NOT WORKING
	//ShellExecute(NULL, "open", f, NULL, NULL, SW_SHOWNORMAL);
	char	*cmd;
	char	c[] = "open ";
	//char	c[] = "start ";
	char	*cm;
	char	*w;
	
	cm = &c[0];
	cmd = malloc(length(cm) + length(f));
	w = cmd;
	while (*cm)
	{
		*w = *cm;
		w++;
		cm++;
	}
	while (*f)
	{
		*w = *f;
		w++;
		f++;
	}
	system(cmd);
}

int		strdif(char *a, char *b)
{
	if (!a) return (0);
	if (!b) return (0);
	while ((*a) && (*b))
	{
		if (*a != *b) return (*b - *a);
		a++;
		b++;
	}
	return (*b - *a);
}

book	*swich(book *a, book *b)
{
	if (a->pv) a->pv->nx = b;
	if (b->nx) b->nx->pv = a;
	a->nx = b->nx;
	b->pv = a->pv;
	a->pv = b;
	b->nx = a;
	return (b);
}

book	*sort(book *k)
{
	book	*i;
	int		ops;

	ops = 1;
	i = k;
	while (ops)
	{
		//printf("ops\n");
		k = i;
		ops = 0;
		while (k->nx)
		{
//			printf("%.5s - %.5s ", k->a, k->nx->a);
			if (strdif(k->a, k->nx->a) < 0)
			{
				if (i == k) i = k->nx;
				k = swich(k, k->nx);
				ops = 1;
				//printf("*");
				k = k->nx;
			}
//			printf("\n");
			k = k->nx;
		}
	}
	return (i);
}

int main(void)
{
	char	*j;
	char	*t;
	book	*b;
	char	*bibli;
	
	b = init_book(0);
	j = file_content("list.txt");
	while (*j) 
	{
		JJ("//") { NC }
		J("#") { t = get_line(j); }
		J("A") { 
			b = init_book(b);
			b->a = get_line(j);
		}
		J("T") { b->t = get_line(j); }
		J("R") { b->r = get_line(j); }
		J("E") { b->e = get_line(j); }
		J("P") { b->p = get_line(j); }
		J("Y") { b->y = get_line(j); }
		J("O") { b->o = get_line(j); }
		J("L") { b->l = get_line(j); }
		J("I") { b->i = get_line(j); }
		J("N") { b->n = get_line(j); }
		N
	}
	//printf("\nTemplate:\n%s\n\n", t);
	b = sort(b);
	bibli = print_book(b, t);
	save_book(bibli);
//	open_browser("bibli.htm");
}
