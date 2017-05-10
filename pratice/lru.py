#!/bin/env python
# -*- coding: utf-8 -*-

"""
LRU Cache:
    1.get(key) – 如果该元素(总是正数)存在，将该元素移动到lru头部，并返回该元素的值，否则返回-1。
    2.set(key,value) – 设置一个key的值为value(如果该元素存在),并将该元素移动到LRU头部。否则插入一个key,且值为value。如果在设置前检查到，该key插入后，会超过cache的容量，则根据LRU策略，删除最近最少使用的key。
"""

class Node(object):
    key = None
    value = None
    pre = None
    next = None

    def __init__(self, key, value):
        self.key = key
        self.value = value

class LRUCache(object):
    capacity = 0
    map = {}
    head = None
    end = None

    def __init__(self, capacity):
        self.capacity = capacity

    def get(self, key):
        if key in self.map:
            node = self.map[key]
            self.remove(node)
            self.setHead(node)
        else:
            return -1

    def getAllKeys(self):
        keys = []
        tmpNode = None
        if self.head:
            tmpNode = self.head
            while tmpNode:
                keys.append(tmpNode.key)
                tmpNode = tmpNode.next
        return keys

    def remove(self, n):
        if n.pre:
            n.pre.next = n.next
        else:
            self.head = n.next

        if n.next:
            n.next.pre = n.pre
        else:
            self.end = n.pre
        n.pre = None
        n.next = None

    def setHead(self, n ):
        n.next = self.head
        n.pre = None
        if self.head:
            self.head.pre = n
        self.head = n
        if not self.end:
            self.end = self.head

    def set(self, key, value):
        if key in self.map:
            oldNode = self.map[key]
            oldNode.value = value
            self.remove(oldNode)
            self.setHead(oldNode)
        else:
            node = Node(key, value)
            if len(self.map) >= self.capacity:
                self.map.pop(self.end.key)
                self.remove(self.end)
                self.setHead(node)
            else:
                self.setHead(node)
            self.map[key] = node

def main():
    cache = LRUCache(100)
    cache.set('a', '1')
    cache.set('b', '2')
    cache.set('c', 3)
    cache.set('d', 4)
    print cache.getAllKeys()
    cache.get('c')
    print cache.getAllKeys()
    cache.set('b', 'b')
    print cache.getAllKeys()

if __name__ == '__main__':
    main()
