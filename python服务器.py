import socket                   # Import socket module

port = 6000                    # Reserve a port for your service.
s = socket.socket()             # Create a socket object
s.bind(('192.168.208.213', port))            # Bind to the port
s.listen(5)                     # Now wait for client connection.

print 'Server listening....'

while True:
    conn, addr = s.accept()     # Establish connection with client.
    print 'Got connection from', addr
    data = conn.recv(1024)
    print('Server received', repr(data))

    conn.send('3')
    print('Sent')

    print('Done sending')
    #conn.send('Thank you for connecting')
    conn.close()
