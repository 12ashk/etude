int conv(char c)
{
	int i;
	char amino[20] = {'A', 'R', 'N', 'D', 'C', 'Q',
		'E', 'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V'};
	for(i = 0; i < 20; i++){
		if(amino[i] == c){
			return i;
		}
	}
}

int score[20] = 
 /* A  R  N  D  C  Q  E  G  H  I  L  K  M  F  P  S  T  W  Y  V*/
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1};

int convert(char c){
	return score[conv(c)];
}
