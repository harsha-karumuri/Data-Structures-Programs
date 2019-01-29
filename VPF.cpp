Vector Vector::operator* (Vector &param) {  
  Vector mulVector;
  if (size != param.size) cout << " Something is wrong ..." << endl;
  cout << " Same size vectors found, Multiplying vectors items now..." << endl;
  link itA = first;
  link itB = param.getFirst();

	while (itA != NULL && itB != NULL )
	  {
		  if (itA->index < itB->index)
		   {
			    itA = itA->next;
		   }
		  else if (itA->index > itB->index)
		   {
				itB= itB->next;
		   }
		  else
		   {
			    mulVector.mul(itA->index, itB->data * itA->data  );
			    itA = itA-> next;
			    itB = itB-> next;
		   }
	  }
  return mulVector;
}
