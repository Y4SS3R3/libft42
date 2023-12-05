void print(char *c)
{
	printf("%s\n", c);
}

int main()
{
	void (* ptr)(void *) = print;
}
