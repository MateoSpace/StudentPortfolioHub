import socket

"""
#server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # a todos los dispositivos
server.bind(("0.0.0.0", 5000))  # Escucha en todas las interfaces
#server.listen(1)

print("Esperando conexión en el puerto 5000...")
conn, addr = server.accept()
print(f"Conectado desde {addr}")

while True:
    data = conn.recv(1024)
    if not data:
        break
    print("Datos recibidos:", data.decode())

conn.close()
"""

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP
server.bind(("0.0.0.0", 5000))

print("Esperando datos...")

while True:
    try:
        data, addr = server.recvfrom(1024)
        print(f"Datos recibidos desde {addr}: {data.decode()}")
    except KeyboardInterrupt:
        print("Servidor detenido.")
        break
    except Exception as e:
        print(f"Error: {e}")
