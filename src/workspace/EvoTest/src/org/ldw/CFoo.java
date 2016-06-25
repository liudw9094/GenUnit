package org.ldw;

public class CFoo {
	void Bar(String a, int b) throws Exception {
		String p = "";
		if("a".equals(a))
			p = "haha";
		else if("abc".equals(a))
			p = "haha1";
		else if("add".equals(a))
		{
			assert(b != 32); // b != 32
			p = "9d2w";
		}
		else if(a.equals("adv")) // a != NULL
			p = "bbbbb";
		else if("vs".equals(a))
			p = "hhhh";
		else if("13".equals(a))
		{
			if(b < 78) // b >= 78
				throw new ExcpBadInput();
			assert(b < 132); // b < 132
			p = "1345";
		}
		else if("dv".equals(a))
			p = "vc";
		else if("gb".equals(a))
		{
			if(b > 0)
				p = "dd";
			else
				p = "ff";
		}
		int cons = 3994/(b-29); // b != 29
		p = p + cons;
		System.out.println(p);
	}
}
