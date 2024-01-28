from graphviz import Digraph

# Create a Digraph object
dot = Digraph(comment='Non-Perishable Items Checkout')

# Add nodes and edges to the flowchart
dot.node('A', 'Start Checkout')
dot.node('B', 'Prompt User to Scan Item')
dot.node('C', 'Scan Item')
dot.node('D', 'Check Scan Validity')
dot.node('E', 'Scan Fails - Prompt Rescan')
dot.node('F', 'Retrieve Item Details from Black Box')
dot.node('G', 'Display Item & Price')
dot.node('H', 'Update Basket & Subtotal')
dot.node('I', 'Ask to Continue Scanning')
dot.node('J', 'End Checkout')
dot.node('K', 'End')

# Flow from Start to Prompt User
dot.edges(['AB'])
# Flow from Prompt User to Scan Item
dot.edges(['BC'])
# Flow from Scan Item to Check Scan Validity
dot.edges(['CD'])
# Flow from Check Scan Validity to Retrieve Item Details or Rescan Prompt
dot.edge('D', 'F', 'Scan Successful')
dot.edge('D', 'E', 'Scan Fails')
# Loop back if scan fails
dot.edge('E', 'B')
# Flow from Retrieve Item Details to Display Item & Price
dot.edges(['FG'])
# Flow from Display Item & Price to Update Basket
dot.edges(['GH'])
# Flow from Update Basket to Ask to Continue
dot.edges(['HI'])
# Decision node to either Scan More Items or End Checkout
dot.edge('I', 'C', 'Yes')
dot.edge('I', 'J', 'No')
# Flow from End Checkout to End
dot.edges(['JK'])

# Render the flowchart to a file
file_path = '/mnt/data/Checkout_Flowchart_NonPerishable'
dot.render(file_path, format='png', cleanup=True)

file_path+'.png'  # Return the path to the image file

