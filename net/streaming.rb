# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.
#
# This file has been extracted from a talk by Xavier Noria.

#
# This is a simple script that creates a TCP server and then transfers
# the info via streaming. It's not too fancy, I'm just testing the HTTP's
# Transfer-Encoding: chunked;
#


require 'socket'

# This is the message to be sent.
body = <<EOS
  This is just a demo
  hello
  world
EOS

# Create the server at localhost, port 3000
server = TCPServer.new 'localhost', 3000
conn = server.accept
conn.sync = true

# When we got a request, we can send a response.
1 while conn.readline != "\r\n"
conn.close_read

# HTTP headers, with chunked (streaming)
conn.write "HTTP/1.1 200 OK\r\n"
conn.write "Content-Type: text/plain\r\n"
conn.write "Transfer-Encoding: chunked\r\n"
conn.write "Connection: close\r\n\r\n"

# And now, this simulates the response. We first write the bytesize in
# hexadecimal, then we write the line, and finally we call sleep. The sleep
# call is simulating like we're busy doing some other stuff.
body.each_line  do |line|
  conn.write line.bytesize.to_s(16) + "\r\n"
  conn.write line + "\r\n"
  sleep 2
end

# Shut the request.
conn.write "0\r\n\r\n"
conn.close_write
