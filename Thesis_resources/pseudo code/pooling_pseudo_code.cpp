for(int yy=0; yy<Nyin; yy+=Ty) {
  for(int xx=0; xx<Nxin; xx+=Tx) {
    for(int iii=0; iii<Ni; iii+=Tii) {
      // -- 原始代码 --（除去ii循环）
      int yout=0;
      for(int y=yy; y<yy+Ty; y+=sy) {
        int xout=0;
        for(int x=xx; x<xx+Tx; x+=sx) {
          for(int ii=iii; ii<iii+Tii; ii+=Ti)
            for(int i=ii; i<ii+Ti; i++)
              value[i]=0;
            for(int ky=0; ky<Ky; ky++)
              for(int kx=0; kx<Kx; kx++)
                for(int i=ii; i<ii+Ti; i++)
                  // 平均归并版本
		  value[i]+=neuron[ky+y][kx+x][i];
		  // 最大归并版本
		  value[i]=max(value[i], neuron[ky+y][kx+x][i]);
         }
         // 对于平均归并
	 neuron[xout][yout][i]=value[i]/(Kx*Ky);
	 xout++;} yout++; }
}}
