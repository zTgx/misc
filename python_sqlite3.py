//command line
>>> import sqlite3
>>> conn = sqlite3.connect('ledger.db')
>>> cursor = conn.cursor()
>>> cursor.execute('command')
<sqlite3.Cursor object at 0x00000000034DFCE0>
>>> values = cursor.fetchall()
>>> values
