for(int nnn=0; nnn<Nn; nnn+=Tnn) {  // Ϊ�����Ԫ�ֿ�
  for(int iii=0;iii<Ni; iii+=Tii) {  // Ϊ������Ԫ�ֿ�
    for(int nn=nnn; nn<nnn+Tnn; nn+=Tn) {
      for(int n=nn; n<nn+Tn; n++)
        sum[n]=0;
      for(int ii=iii; ii<iii+Tii; ii+=Ti)
        // -- ԭʼ���� --
        for(int n=nn; n<nn+Tn; n++)
          for(int i=ii; i<ii+Ti; i++)
            sum[n]+=synapse[n][i]*neuron[i];
      for(int n=nn; n<nn+Tn; n++)
        neuron[n]=sigmoid(sum[n]);
}}}
