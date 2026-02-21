import requests
from dataclasses import dataclass

@dataclass
class StatusReponse:
    status: int
    message: str

res = requests.get("http://127.0.0.1:8080/status")
assert res.ok
status_res = StatusReponse(**res.json())
assert status_res.status == 200
