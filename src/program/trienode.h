/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2019 Fritzing

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************/


#ifndef TRIENODE_H_
#define TRIENODE_H_

#include <QChar>
#include <QList>

class TrieLeaf {
public:
	TrieLeaf();
	virtual ~TrieLeaf();
};

class TrieNode
{
public:
	TrieNode(QChar);
	virtual ~TrieNode();

	virtual void addString(QString & s, bool caseInsensitive, TrieLeaf * leaf);
	virtual bool matches(QString & string, TrieLeaf * & leaf);

protected:
	virtual void addStringAux(QChar c, QString & next, bool caseInsensitive, TrieLeaf * leaf);
	virtual bool matchesChar(QChar c);

protected:
	QChar m_char;
	bool m_caseInsensitive;
	QList<TrieNode *> m_children;
	TrieLeaf * m_leafData;
	bool m_isLeaf;
};

#endif /* TRIENODE_H_ */
