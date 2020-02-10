package mainStack;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Stack;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.ScrollPaneConstants;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import javax.swing.border.MatteBorder;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;

@SuppressWarnings("serial")
public class InfixPostfix extends JFrame 
{
	private JPanel contentPane;
	private JTextField txtInput;
	private JTable table;
	private JTextField txtOutput;
	Stack<Character> stack = new Stack<>();
	public static void main(String[] args) 
	{
		EventQueue.invokeLater(new Runnable() 
		{
			public void run() 
			{
				try 
				{
					InfixPostfix frame = new InfixPostfix();
					frame.setVisible(true);
				} 
				catch (Exception e) 
				{
					e.printStackTrace();
				}
			}
		});
	}
	public InfixPostfix() 
	{
		setTitle("Convert Infix String to Postfix");
		setBounds(100, 100, 893, 465);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		JPanel inputPane = new JPanel();
		inputPane.setLayout(null);
		inputPane.setBorder(new TitledBorder(new MatteBorder(2, 3, 2, 3, (Color) new Color(0, 0, 0)),
						"Enter your Expression", TitledBorder.LEADING, TitledBorder.TOP, new Font("Courier New", Font.BOLD, 15), null));
		
		txtInput = new JTextField();
		txtInput.setFont(new Font("Courier New", Font.PLAIN, 16));
		txtInput.setColumns(10);
		txtInput.setBounds(10, 30, 356, 39);
		inputPane.add(txtInput);
		
		JButton btnInput = new JButton("Convert Here");
		btnInput.setFont(new Font("Courier New", Font.BOLD, 15));
		btnInput.setBounds(103, 80, 152, 40);
		inputPane.add(btnInput);
		
		JPanel outputPane = new JPanel();
		outputPane.setBorder(new MatteBorder(2, 3, 3, 2, (Color) new Color(0, 0, 0)));
		
		JLabel label = new JLabel("Postfix Expression: ");
		label.setFont(new Font("Courier New", Font.BOLD, 14));
		
		txtOutput = new JTextField();
		txtOutput.setHorizontalAlignment(SwingConstants.CENTER);
		txtOutput.setFont(new Font("Courier New", Font.PLAIN, 16));
		txtOutput.setEditable(false);
		txtOutput.setColumns(10);
		
		JButton txtReset = new JButton("Reset");
		txtReset.setFont(new Font("Courier New", Font.BOLD, 15));
		
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(10)
							.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING)
								.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
									.addGroup(gl_contentPane.createSequentialGroup()
										.addPreferredGap(ComponentPlacement.RELATED)
										.addComponent(inputPane, GroupLayout.PREFERRED_SIZE, 376, GroupLayout.PREFERRED_SIZE))
									.addGroup(gl_contentPane.createSequentialGroup()
										.addPreferredGap(ComponentPlacement.RELATED)
										.addComponent(label, GroupLayout.PREFERRED_SIZE, 181, GroupLayout.PREFERRED_SIZE)))
								.addGroup(gl_contentPane.createSequentialGroup()
									.addComponent(txtOutput, GroupLayout.PREFERRED_SIZE, 356, GroupLayout.PREFERRED_SIZE)
									.addPreferredGap(ComponentPlacement.UNRELATED))))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(99)
							.addComponent(txtReset, GroupLayout.PREFERRED_SIZE, 152, GroupLayout.PREFERRED_SIZE)))
					.addComponent(outputPane, GroupLayout.DEFAULT_SIZE, 481, Short.MAX_VALUE))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addComponent(outputPane, GroupLayout.DEFAULT_SIZE, 416, Short.MAX_VALUE)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addComponent(inputPane, GroupLayout.PREFERRED_SIZE, 129, GroupLayout.PREFERRED_SIZE)
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addComponent(label, GroupLayout.PREFERRED_SIZE, 29, GroupLayout.PREFERRED_SIZE)
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addComponent(txtOutput, GroupLayout.PREFERRED_SIZE, 39, GroupLayout.PREFERRED_SIZE)
					.addGap(37)
					.addComponent(txtReset, GroupLayout.PREFERRED_SIZE, 40, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(120, Short.MAX_VALUE))
		);
		
		table = new JTable();
		table.setFont(new Font("Courier New", Font.BOLD, 13));
		GroupLayout gl_outputPane = new GroupLayout(outputPane);
		gl_outputPane.setHorizontalGroup(
			gl_outputPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_outputPane.createSequentialGroup()
					.addContainerGap()
					.addComponent(table, GroupLayout.DEFAULT_SIZE, 446, Short.MAX_VALUE)
					.addContainerGap())
		);
		gl_outputPane.setVerticalGroup(
			gl_outputPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_outputPane.createSequentialGroup()
					.addContainerGap()
					.addComponent(table, GroupLayout.DEFAULT_SIZE, 389, Short.MAX_VALUE)
					.addContainerGap())
		);
		outputPane.setLayout(gl_outputPane);
		contentPane.setLayout(gl_contentPane);
		
		DefaultTableModel tm = new DefaultTableModel();
		table.setModel(tm);
		Object[] cols = {"Symbol Scanned","Stack","Postfix Expression"};
		tm.setColumnIdentifiers(cols);
		
		JScrollPane jsp = new JScrollPane(table,ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		outputPane.add(jsp);
		gl_outputPane.setHorizontalGroup(
				gl_outputPane.createParallelGroup(Alignment.LEADING)
					.addGroup(gl_outputPane.createSequentialGroup()
						.addContainerGap()
						.addComponent(jsp, GroupLayout.DEFAULT_SIZE, 446, Short.MAX_VALUE)
						.addContainerGap())
			);
			gl_outputPane.setVerticalGroup(
				gl_outputPane.createParallelGroup(Alignment.LEADING)
					.addGroup(gl_outputPane.createSequentialGroup()
						.addContainerGap()
						.addComponent(jsp, GroupLayout.DEFAULT_SIZE, 389, Short.MAX_VALUE)
						.addContainerGap())
			);
		
		Object row[] = new Object[3];
		btnInput.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0)
			{
				for( int i = tm.getRowCount() - 1; i >= 0; i-- ) 
				{
			        tm.removeRow(i);
				}
				StringBuffer expr = new StringBuffer();
				int i;
				String postfix = "";
				char c,t;;
				String input = txtInput.getText();
				stack.push('\0');
				t = input.charAt(0);
				for (i = 0; i < input.length(); i++) 
				{
					t = input.charAt(i);
					if(Character.isDigit(input.charAt(i)) || Character.isAlphabetic(input.charAt(i)))
					{
						postfix =postfix + t;
						if(i == input.length()-1);
						else
						{
							row[0] = t;
							row[1] = expr.toString();
							row[2] = postfix;
							tm.addRow(row);
						}
					}
					else if(t == '(')
					{
						stack.push(t);
						expr = expr.append(t);
						row[0] = t;
						row[1] = expr.toString();
						row[2] = postfix;
						tm.addRow(row);
					}
					else if(t == ')')
					{
						while(stack.peek() != '(')
						{
							c = stack.pop();
							postfix =postfix + c;
							expr = expr.deleteCharAt(expr.length()-1);
						}
						expr = expr.deleteCharAt(expr.length()-1);
						row[0] = t;
						row[1] = expr.toString();
						row[2] = postfix;
						tm.addRow(row);
						c = stack.pop();
					}
					else
					{
						while(prece(stack.peek())>=prece(t))
						{
							c = stack.pop();
							postfix =postfix + c;
							expr = expr.deleteCharAt(expr.length()-1);
						}
						expr = expr.append(t);
						row[0] = t;
						row[1] = expr.toString();
						row[2] = postfix;
						tm.addRow(row);
						stack.push(t);
					}
				}
				while(stack.peek() != 0)
				{
					c = stack.pop();
					postfix = postfix + c;
				}
				row[0] = t;
				row[1] = "Empty";//expr.toString();
				row[2] = postfix;
				tm.addRow(row);
				txtOutput.setText(postfix);
			}
		});
		txtReset.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				for( int i = tm.getRowCount() - 1; i >= 0; i-- ) 
				{
			        tm.removeRow(i);
				}
		        txtInput.setText("");
		        txtOutput.setText("");
			}
		});
	}
	static int prece(char t)
	{
		int i=3;
		switch(t)
		{
		case '+':
			i = 7;
		case '-':
			i = 7;
			return i;
		case '*':
			i = 8;
			return i;
		case '/':
			i = 9;
			return i;
		case '^':
			return 10;
		case '\0':
			return (0);
		default:
			break;
		}
		return 0;
	}
}
