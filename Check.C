unsigned char Is_Valid	(unsigned char min, unsigned char max, unsigned char number){ 
	if(number<min)
		return 0;
	else if(number> max)
		return 0;
	else
		return 1;
}
