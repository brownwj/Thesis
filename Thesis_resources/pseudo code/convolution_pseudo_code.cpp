for(int yy=0; yy<Nyin; yy+=Ty) {
  for(int xx=0; xx<Nxin; xx+=Tx) {
    for(int nnn=0; nnn<Nn; nnn+=Tnn) {
      // -- ԭʼ���� -- ����ȥnnѭ����iiѭ����
      int yout=0;
      for(int y=yy; y<yy+Ty; y+=sy) { // Ϊy�ֿ�
        int xout=0;
	for(int x=xx; x<xx+Tx; x+=sx) { // Ϊx�ֿ�
          for(int nn=nnn; nn<nnn+Tnn; nn+=Tn) {
            for(int n=nn; n<nn+Tn; n++)
              sum[n]=0;
            // ��������
	    for(int ky=0; ky<Ky; ky++)
              for(int kx=0; kx<Kx; kx++)
                for(int ii=0; ii<Ni; ii+=Ti)
                  for(int n=nn; n<nn+Tn;n++)
                    for(int i=ii; i<ii+Ti; i++)
                      // ����˰汾
                      sum[n]+=synapse[ky][kx][n][i]
			      *neuron[ky+y][kx+x][i];
		      // ˽�к˰汾
		      sum[n]=synapse[yout][xout][ky][kx][n][i]
			      *neuron[ky+y][kx+x][i];
             for(int n=nn; n<nn+Tn; n++)
               neuron[yout][xout][n]=non_linear_transform(sum[n]);
             } xout++;} yout++;}
}}}
