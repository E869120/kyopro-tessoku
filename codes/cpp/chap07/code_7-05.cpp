int CurrentPlace = 0;
for (int i = T; i >= 1; i--) {
	Answer[i] = Beam[i][CurrentPlace].LastMove;
	CurrentPlace = Beam[i][CurrentPlace].LastPos;
}
