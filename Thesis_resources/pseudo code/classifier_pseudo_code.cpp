for(int nnn=0; nnn<Nn; nnn+=Tnn) {  // 为输出神经元分块
  for(int iii=0;iii<Ni; iii+=Tii) {  // 为输入神经元分块
    for(int nn=nnn; nn<nnn+Tnn; nn+=Tn) {
      for(int n=nn; n<nn+Tn; n++)
        sum[n]=0;
      for(int ii=iii; ii<iii+Tii; ii+=Ti)
        // -- 原始代码 --
        for(int n=nn; n<nn+Tn; n++)
          for(int i=ii; i<ii+Ti; i++)
            sum[n]+=synapse[n][i]*neuron[i];
      for(int n=nn; n<nn+Tn; n++)
        neuron[n]=sigmoid(sum[n]);
}}}
