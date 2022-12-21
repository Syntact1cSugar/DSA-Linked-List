public class CSLinkedList
{
	//Class Declaration of node
	public class Node
	{
		private int data;
		private Node link;
		public Node()
		{
			this.data = 0;
			this.link = null;
		}
		public Node(int data)
		{
			this.data = data;
			this.link = null;
		}
		public Node(int data,Node link)
		{
			this.data = data;
			this.link = link;
		}
		//Getters
		public int getData()
		{
			return this.data;
		}
		public Node getLink()
		{
			return this.link;
		}
		//Setters
		public void setData(int data)
		{
			this.data = data;
			return;
		}
		public void setLink(Node link)
		{
			this.link = link;
		}
	}
	/**End*/


	private Node head;
	private int count;
	//Constructor
	public CSLinkedList()
	{
		this.head = null;
		this.count = 0;
	}
	//Addtional functions
	public Node getHead()
	{
		return this.head;
	}
	public int getCount()
	{
		return this.count;
	}
	public boolean isEmpty()
	{
		return (this.head == null)? true : false;
	}
	public int Display()
	{
		if(this.isEmpty())return 0;
		Node auxPtr = this.head;
		do
		{
			System.out.print(auxPtr.getData()+"\t");
			auxPtr = auxPtr.getLink();
		}
		while(auxPtr != this.head);
		System.out.println();
		return 1;
	}
	//Insert Implementation
	public int insertFront(int dataIn)
	{
		Node newP = new Node(dataIn,this.head);
		if(this.isEmpty())newP.setLink(newP);
		else
		{
			Node auxPtr = this.head;
			while(auxPtr.getLink() != head)
				auxPtr = auxPtr.getLink();
			auxPtr.setLink(newP);
		}
		this.head = newP;
		(this.count)++;
		return 1;
	}
	public int insertRear(int dataIn)
	{
		Node newP = new Node(dataIn,this.head);
		if(this.isEmpty())
		{
			newP.setLink(newP);
			this.head = newP;
		}
		else
		{
			Node auxPtr = this.head;
			while(auxPtr.getLink() != this.head)
				auxPtr = auxPtr.getLink();
			auxPtr.setLink(newP);
		}
		(this.count)++;
		return 1;
	}
	//Delete Implementation
	public int deleteFront()
	{
		if(this.isEmpty())return 0;
		Node auxPtr = this.head;
		while(auxPtr.getLink() != this.head)
			auxPtr = auxPtr.getLink();
		if(this.head.getLink() == this.head)//Only one node
		{
			this.head = null;
			auxPtr = null;
		}
		else
		{
			this.head = this.head.getLink();
			auxPtr.setLink(this.head);
		}
		System.gc();
		(this.count)--;
		return 1;
	}
	public int deleteRear()
	{
		if(this.isEmpty())return 0;
		if(this.head.getLink() == this.head)//Only one node in the list
			this.head = null;
		else
		{
			Node auxPtr = this.head;
			while(auxPtr.getLink().getLink() != head)
				auxPtr = auxPtr.getLink();
			auxPtr.setLink(this.head);
		}
		System.gc();
		(this.count)--;
		return 1;
	}
}
