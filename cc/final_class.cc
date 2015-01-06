// file final_class.cc

//the link:
//http://zhedahht.blog.163.com/blog/static/25411174200793181548842/

// way one:not easy to use
class FinalClass1
{
	public:
		static FinalClass1* GetInstance()
		{
			return new FinalClass1;
		}

		static void DeleteInstance( FinalClass1* pInstance)
		{
			delete pInstance;
			pInstance = 0;
		}

	private:
		FinalClass1() {}
		~FinalClass1() {}
};

// way second:elegant implementation
template <typename T> class MakeFinal
{
	      friend T;
		   
	private:
		        MakeFinal() {}
				      ~MakeFinal() {}
};
 
class FinalClass2 : virtual public MakeFinal<FinalClass2>
{
	public:
		      FinalClass2() {}
			        ~FinalClass2() {}
};

// way third:
class FinalHelper 
{ 
protected: 
	  FinalHelper()
	  {
	  
	  } 
}; 

class AFinalCls : private virtual FinalHelper 
{ 

}; 


int main(int argc, char* argv[])
{
	FinalClass2	fc2;
	AFinalCls	afcl;

	return 0;
}

