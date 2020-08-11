ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == NULL)
        return NULL;
    if(!k)
        return NULL;
    
    ListNode* pAhead = pListHead;
    ListNode* pBehind = pListHead;
    
    for(unsigned int i=0; i< k-1;i++) {
        pAhead=pAhead->m_pNext;
    }
    
    while(pAhead->m_pNext!=NULL) {
        pAhead=pAhead->m_pNext;
        pBehind=pBehind->m_pNext;
    }
    
    return pBehind;
}