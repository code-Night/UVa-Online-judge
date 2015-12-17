import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Main {

	private static class node {
		boolean isEnd = false;

		node[] childern = new node[26];
	}

	private static class Trie {
		private node root = new node();

		public Trie() {
		}

		public void insert(String s, node curr, int n) {
			if (n == s.length())
				return;
			char c = s.charAt(n);
			if (curr.childern[c - 'a'] == null)
				curr.childern[c - 'a'] = new node();
			insert(s, curr.childern[c - 'a'], n + 1);
		}

		public String findPrefix(String Q, node curr, int i) {
			if (i == Q.length())
				return "";
			char c = Q.charAt(i);
			if (curr.childern[c - 'a'] == null)
				return "";
			return c + findPrefix(Q, curr.childern[c - 'a'], i + 1);
		}
	}

	public static void main(String[] args) {
		Trie t = null;
		Scanner s = new Scanner(System.in);
		while (true) {
			t = new Trie();
			String a = s.nextLine();
			String b = s.nextLine();
			String perfix = "";
			for (int i = b.length() - 1; i >= 0; i--) {
				perfix = b.charAt(i) + perfix;
				t.insert(perfix, t.root, 0);
			}
			perfix = "";
			int maxLen = 0;
			HashSet<String> output = new HashSet<String>();
			for (int i = a.length() - 1; i >= 0; i--) {
				perfix = a.charAt(i) + perfix;
				String str = t.findPrefix(perfix, t.root, 0);
				if (str.length() > maxLen) {
					output.clear();
					output.add(str);
					maxLen = str.length();
				} else if (str.length() == maxLen && str.length() > 0)
					output.add(str);
			}
			String arr [] = new String [output.size()] ;
			arr =  output.toArray(arr);
			Arrays.sort(arr);
			if (output.size() == 0)
				System.out.println("No common sequence.");
			for (int i = 0; i < arr.length ; i++)
				System.out.println(arr[i]);
			if(!s.hasNextLine())
				break ;
			else{
				s.nextLine();
				System.out.println();
			}
		}
	}
}
