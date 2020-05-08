typedef struct {
	int ord;
	PosType seat;
	int di;
}SElemType; // Delement type of stack

Status MazePath( MazeType maze, PosType start, PosType end ) {
	InitStack(S); curpos = start;
	curstep = 1;
	do {
		if (Pass( curpos)) {
			FootPrint(curpos);
			e = (curstep, curpos, 1);
			Push(S, e);
			if (curpos == end) return (TRUE);
			curpos = NextPos(curpos, 1);
			curstep++;
		}
		else {
			if(!StackEmpty(S)) {
				Pop(S, e);
				while(e.di == 4 && !StackEmpty(S)) {
					MarkPrint(e.seat); Pop(S, e);
				}
				if(e.di < 4) {
					e.di++; Push(S, e);
					curpos = NextPos(e.seart, e.di);
				}
			}
		}
	}while(!StackEmpty(S));
	return (FALSE);
}
