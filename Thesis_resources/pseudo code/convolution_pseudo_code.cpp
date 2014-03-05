for(int yy=0; yy<Nyin; yy+=Ty) {
  for(int xx=0; xx<Nxin; xx+=Tx) {
    for(int nnn=0; nnn<Nn; nnn+=Tnn) {
      // -- 原始代码 -- （除去nn循环和ii循环）
      int yout=0;
      for(int y=yy; y<yy+Ty; y+=sy) { // 为y分块
        int xout=0;
	for(int x=xx; x<xx+Tx; x+=sx) { // 为x分块
          for(int nn=nnn; nn<nnn+Tnn; nn+=Tn) {
            for(int n=nn; n<nn+Tn; n++)
              sum[n]=0;
            // 滑动窗口
	    for(int ky=0; ky<Ky; ky++)
              for(int kx=0; kx<Kx; kx++)
                for(int ii=0; ii<Ni; ii+=Ti)
                  for(int n=nn; n<nn+Tn;n++)
                    for(int i=ii; i<ii+Ti; i++)
                      // 共享核版本
                      sum[n]+=synapse[ky][kx][n][i]
			      *neuron[ky+y][kx+x][i];
		      // 私有核版本
		      sum[n]=synapse[yout][xout][ky][kx][n][i]
			      *neuron[ky+y][kx+x][i];
             for(int n=nn; n<nn+Tn; n++)
               neuron[yout][xout][n]=non_linear_transform(sum[n]);
             } xout++;} yout++;}
}}}
