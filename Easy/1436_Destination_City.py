# LeetCode 1436: Destination City

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        dic = {}
        for path in paths:
            dic[path[0]] = 1
        for path in paths:
            if path[1] not in dic:
                return path[1]
        return ""