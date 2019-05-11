#!/usr/bin/python3
import sys
from xml.dom import minidom
xmldoc = minidom.parse(sys.stdin)
itemlist = xmldoc.getElementsByTagName('variant')
print(itemlist[0].childNodes.item(0).nodeValue)
