unsigned char Is_Valid	(int min, int max, int number){ 
	if(number<=min)
		return 0;
	else if(number>=max)
		return 0;
	else
		return 1;
}
