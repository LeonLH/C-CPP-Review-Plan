

void TestShift(){
	char i = 0x80;
	char j = i<<1;
	j = i<<2;
	j = i<<4;
	char k = i>>1;
	k = i>>2;
	k = i>>4;

	i = 0xc0;
	j = i<<1;
	j = i<<2;
	j = i<<4;
	k = i>>1;
	k = i>>2;
	k = i>>4;

	i = 0xf0;
	j = i<<1;
	j = i<<2;
	j = i<<4;
	k = i>>1;
	k = i>>2;
	k = i>>4;

	i = 0x70;
	j = i<<1;
	j = i<<2;
	j = i<<4;
	k = i>>1;
	k = i>>2;
	k = i>>10;

	i = 0x07;
	j = i<<1;
	j = i<<2;
	j = i<<4;
	k = i>>1;
	k = i>>2;
	k = i>>4;

	i = 0x7f;
	j = i<<1;
	j = i<<2;
	j = i<<4;
	k = i>>1;
	k = i>>2;
	k = i>>4;
	
}